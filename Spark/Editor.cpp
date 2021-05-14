#include "Editor.h"

using namespace sf;
Editor::Editor(SharedGameState& s)
{
	ss = std::move(s);
}
#include <iostream>
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
			deltaPos = Vector2i((int)ss.totalScroll.x % tileSize, (int)ss.totalScroll.y % tileSize);
			startPos = LevelReader::clampToTile(mPos) - deltaPos;
		}
		else if (e.type == Event::MouseButtonReleased) {
			Vector2i size = endPos - startPos;
			ss.tiles.push_back(std::make_unique<Tile>((Vector2f)startPos,(Vector2f)size));
			ss.level.addBlock(Color(0, size.x, size.y), startPos,(Vector2i)ss.totalScroll, size);
			drawPreview = 0;
		}
	}
	auto mPos = m.getPosition(window);
	endPos = LevelReader::clampToTile(mPos, { 1,1 }) - deltaPos;
}
