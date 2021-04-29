#include "Game.h"

Game::Game()
{
	gameState = std::make_unique<PlayState>();
}

void Game::handleInput(sf::Event& e)
{

	gameState->handleInput(e);
}

void Game::draw(sf::RenderWindow& window)
{
	gameState->draw(window);
}

void Game::update(float delta)
{
	gameState->update(delta);
}
