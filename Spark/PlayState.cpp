#include "PlayState.h"
using namespace sf;

PlayState::PlayState()
{
	tiles.push_back(std::make_unique<Tile>());
	//enemies.push_back(std::make_unique<Enemy>());
}

void PlayState::handleInput(sf::Event& e)
{
	player.handleInput(e);
	scroll.x = -player.getDir().x * scrollSpeed;
	scroll.y = -player.getDir().y * scrollSpeed;
}

void PlayState::draw(sf::RenderWindow& window)
{
	player.draw(window);
	for (int i = 0; i < tiles.size(); i++) tiles[i]->draw(window);
	//for (int i = 0; i < enemies.size(); i++) enemies[i]->draw(window);
}

void PlayState::update(float delta)
{
	player.update(delta);
	for (int i = 0; i < tiles.size(); i++)
		tiles[i]->update(delta, scroll);
	//for (int i = 0; i < enemies.size(); i++) enemies[i]->update(delta, scroll);

	checkCollision(delta);
}

void PlayState::checkCollision(float delta)
{
	for (int i = 0; i < tiles.size(); i++) {
		player.checkCollision(*tiles[i]);
		//for (int j = 0; j < enemies.size(); j++) enemies[j]->defaultResolveCollision(*tiles[i]);
	}
}