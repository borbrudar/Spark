#include "GameState.h"
using namespace sf;

void GameState::draw(sf::RenderWindow& window)
{
	ss.player.draw(window);
	for (int i = 0; i < ss.tiles.size(); i++) ss.tiles[i]->draw(window);
}

SharedGameState& GameState::getState()
{
	return ss;
}
