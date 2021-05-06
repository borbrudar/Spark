#include "Editor.h"

using namespace sf;
Editor::Editor(SharedGameState& s)
{
	ss = std::move(s);
}

void Editor::handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow &window)
{
	if (m.isButtonPressed(Mouse::Left)) {
		ss.tiles.push_back(std::make_unique<Tile>(sf::Vector2f(m.getPosition(window))));
	}
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
}

void Editor::update(float delta)
{
	for(int i = 0; i < ss.tiles.size();i++)
	ss.tiles[i]->update(delta, sf::Vector2f(0, 0));
}
