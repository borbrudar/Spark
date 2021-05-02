#include "PlayerState.h"
using namespace sf;
std::unique_ptr<PlayerState> PlayerState::handleInput(sf::Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Left) xdir = -1;
		if (e.key.code == Keyboard::Right) xdir = 1;
	}
	if (e.type == Event::KeyReleased) {
		if (e.key.code == Keyboard::Left) xdir = 0;
		if (e.key.code == Keyboard::Right) xdir = 0;
	}

	return nullptr;
}

sf::Vector2i PlayerState::getDir()
{
	return sf::Vector2i(xdir,ydir);
}
