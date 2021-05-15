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
}

void PlayState::update(float delta)
{
	ss.player.update(delta);
	scroll.x = -ss.player.getDir().x * scrollSpeed;
	scroll.y = -ss.player.getDir().y * scrollSpeed;
	ss.totalScroll -= Vector2f(scroll.x * delta, scroll.y * delta);

	for (int i = 0; i < ss.entities.size(); i++)
		ss.entities[i]->update(delta, scroll);

	checkCollision(delta);
}

void PlayState::checkCollision(float delta)
{
	for (int i = 0; i < ss.entities.size(); i++) {
		ss.player.checkCollision(*ss.entities[i]);
		ss.entities[0]->checkCollision(*ss.entities[i]);
	}
}