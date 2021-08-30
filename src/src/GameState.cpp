#include "GameState.h"
using namespace sf;

GameState::GameState()
{
	
}

void GameState::draw(sf::RenderWindow& window)
{
	window.setView(ss.gameView);
	if (!ss.level.getLoaded()) ss.level.loadLevel("levels/level1.png", ss.entities, window);
	ss.player.draw(window);
	for (int i = 0; i < ss.entities.size(); i++) ss.entities[i]->draw(window);
}

SharedGameState& GameState::getState()
{
	return ss;
}

void GameState::scrollInput(Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Left) {
			xdir = -1;
		}
		if (e.key.code == Keyboard::Right) xdir = 1;
	}
	if (e.type == Event::KeyReleased) {
		if (e.key.code == Keyboard::Left) xdir = 0;
		if (e.key.code == Keyboard::Right) xdir = 0;
	}
}

void GameState::updateScroll(float delta)
{
 	scroll.x = xdir * scrollSpeed * delta;
	scroll.y = ydir * scrollSpeed * delta;
	ss.totalScroll += scroll;
	ss.loadScroll += scroll;
}
