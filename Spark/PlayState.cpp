#include "PlayState.h"
using namespace sf;

PlayState::PlayState()
{
}

PlayState::PlayState(SharedGameState& s)
{
	ss = std::move(s);
}

void PlayState::handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	ss.player.handleInput(e);
	if (ss.loadScroll.x > tileSize) {
		ss.loadScroll.x -= tileSize;
		ss.level.loadNextLine(1, ss.entities, ss.loadScroll);
	}
	if (ss.loadScroll.x < -tileSize) {
		ss.loadScroll.x += tileSize;
		ss.level.loadNextLine(0, ss.entities, ss.loadScroll);
	}
}

void PlayState::update(float delta)
{
	ss.player.update(delta);
	scroll.x = -ss.player.getDir().x * scrollSpeed * delta;
	scroll.y = -ss.player.getDir().y * scrollSpeed * delta;
	ss.totalScroll -= scroll;
	ss.loadScroll -= scroll;
	//std::cout << -ss.loadScroll.x << std::endl;

	for (int i = 0; i < ss.entities.size(); i++)
		ss.entities[i]->update(delta, scroll);

	checkCollision(delta);
}

void PlayState::checkCollision(float delta)
{
	for (int i = 0; i < ss.entities.size(); i++) {
		ss.player.checkCollision(*ss.entities[i]);
		for (int j = 0; j < ss.entities.size(); j++) {
			ss.entities[i]->checkCollision(*ss.entities[j]);
		}
	}
}