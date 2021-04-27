#include "Game.h"
using namespace sf;

Game::Game()
{
	entities.push_back(std::make_unique<Obstacle>());
}

void Game::handleInput(sf::Event& e)
{
	player.handleInput(e);
	scroll.x = -player.getDir().x * scrollSpeed;
	scroll.y = -player.getDir().y * scrollSpeed;
}

void Game::draw(sf::RenderWindow& window)
{
	player.draw(window);
	for (int i = 0; i < entities.size(); i++) entities[i]->draw(window);
}

void Game::update(float delta)
{
	player.update(delta, Vector2f(0,0));
	for (int i = 0; i < entities.size(); i++)
		entities[i]->update(delta, scroll);
}
