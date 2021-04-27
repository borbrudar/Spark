#include "Game.h"
using namespace sf;

Game::Game()
{
}

void Game::handleInput(sf::Event& e)
{
	player.handleInput(e);
}

void Game::draw(sf::RenderWindow& window)
{
	player.draw(window);
}

void Game::update(float delta)
{
	player.update(delta);
}
