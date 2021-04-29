#include "Game.h"
using namespace sf;

Game::Game()
{
	tiles.push_back(std::make_unique<Tile>());
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
	for (int i = 0; i < tiles.size(); i++) tiles[i]->draw(window);
}

void Game::update(float delta)
{
	player.update(delta, Vector2f(0,0));
	for (int i = 0; i < tiles.size(); i++)
		tiles[i]->update(delta, scroll);

	checkCollision(delta);
}

void Game::checkCollision(float delta)
{
	for (int i = 0; i < tiles.size(); i++) {
		player.resolveCollisionWithImmovable(*tiles[i]);
	}
}