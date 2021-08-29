#include "PlayState.h"
using namespace sf;

PlayState::PlayState()
{
	ss.tiles.push_back(std::make_unique<Tile>(Vector2f(50, 400)));
	ss.tiles.push_back(std::make_unique<Tile>(Vector2f(200, 350)));
	ss.tiles.push_back(std::make_unique<Tile>(Vector2f(270, 170)));
}

PlayState::PlayState(SharedGameState& s)
{
	ss = std::move(s);
}

void PlayState::handleInput(sf::Event& e)
{
	ss.player.handleInput(e);
}

void PlayState::update(float delta)
{
	ss.player.update(delta);
	scroll.x = -ss.player.getDir().x * scrollSpeed;
	scroll.y = -ss.player.getDir().y * scrollSpeed;

	for (int i = 0; i < ss.tiles.size(); i++)
		ss.tiles[i]->update(delta, scroll);
	//for (int i = 0; i < enemies.size(); i++) enemies[i]->update(delta, scroll);

	checkCollision(delta);
}

void PlayState::checkCollision(float delta)
{
	for (int i = 0; i < ss.tiles.size(); i++) {
		ss.player.checkCollision(*ss.tiles[i]);
		//for (int j = 0; j < enemies.size(); j++) enemies[j]->defaultResolveCollision(*tiles[i]);
	}
}