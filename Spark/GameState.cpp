#include "GameState.h"
using namespace sf;

GameState::GameState()
{
	ss.level.loadLevel("levels/level1.png", ss.entities);
}

void GameState::draw(sf::RenderWindow& window)
{
	ss.player.draw(window);
	for (int i = 0; i < ss.entities.size(); i++) ss.entities[i]->draw(window);
}

SharedGameState& GameState::getState()
{
	return ss;
}