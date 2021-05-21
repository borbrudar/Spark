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
	ss.level.loadNextLine(ss.loadScroll, ss.entities);	
}

void PlayState::update(float delta)
{
	
	scroll.x = ss.player.getDir().x * scrollSpeed * delta;
	scroll.y = ss.player.getDir().y * scrollSpeed * delta;
	ss.totalScroll += scroll;
	ss.loadScroll += scroll;

	ss.gameView.move(scroll);
	ss.player.update(delta, scroll);


	for (int i = 0; i < ss.entities.size(); i++)
		ss.entities[i]->update(delta);

	checkCollision(delta);
}

void PlayState::checkCollision(float delta)
{
	for (int i = 0; i < ss.entities.size(); i++) {
		if (!ss.entities[i]->box) continue;
		ss.player.checkCollision(*ss.entities[i]);
		for (int j = 0; j < ss.entities.size(); j++) {
			if (i == j || !ss.entities[j]->box) continue;
			ss.entities[i]->checkCollision(*ss.entities[j]);
		}
	}
}