#include "Editor.h"

using namespace sf;
Editor::Editor(SharedGameState& s)
{
	ss = std::move(s);
}

void Editor::handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	addBlocks(e, m, window);

	if (m.isButtonPressed(Mouse::Right)) {
		Vector2i mPos = m.getPosition(window);
		for (int i = 0; i < ss.tiles.size(); i++) {
			if (ss.tiles[i]->getCollisionBox().contains(mPos)) {
				ss.tiles.erase(ss.tiles.begin() + i);
				break;
			}
		}
	}
}

void Editor::draw(sf::RenderWindow& window)
{
	GameState::draw(window);
	if (drawPreview) Tile::drawPreview((Vector2f)startPos, (Vector2f)endPos, window);
}

void Editor::update(float delta)
{
	for(int i = 0; i < ss.tiles.size();i++)
	ss.tiles[i]->update(delta, sf::Vector2f(0, 0));
}

void Editor::addBlocks(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	if (e.mouseButton.button == Mouse::Left) {
		drawPreview = 1;
		if (e.type == Event::MouseButtonPressed) {
			Vector2i mPos = m.getPosition(window);
			startPos = Vector2i((mPos.x / tileSize) * tileSize, (mPos.y / tileSize) * tileSize);
		}
		else if (e.type == Event::MouseButtonReleased) {
			Vector2f size = Vector2f(endPos.x - startPos.x,
				endPos.y - startPos.y);
			ss.tiles.push_back(std::make_unique<Tile>((Vector2f)startPos, size));
			drawPreview = 0;
		}
	}
	auto mPos = m.getPosition(window);
	endPos = Vector2i((mPos.x / tileSize + 1) * tileSize , (mPos.y / tileSize + 1) * tileSize);
}
