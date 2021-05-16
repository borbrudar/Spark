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
	//scrolling
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Left) xdir = 1;
		if (e.key.code == Keyboard::Right) xdir = -1;
	}
	if (e.type == Event::KeyReleased) {
		if (e.key.code == Keyboard::Left) xdir = 0;
		if (e.key.code == Keyboard::Right) xdir = 0;
	}

	ss.player.handleInput(e);
}

void PlayState::update(float delta)
{
	ss.player.update(delta);
	scroll.x = xdir * scrollSpeed;
	ss.totalScroll -= Vector2f(scroll.x * delta, scroll.y * delta);

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