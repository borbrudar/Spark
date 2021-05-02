#include "PlayerState.h"
using namespace sf;
PlayerState::PlayerState()
{
	box.create({ 100,100 }, { 50,50 });
	playerSprite.setSprite({ 100,100 }, { 50,50 }, Color::Red);
}
void PlayerState::handleInput(sf::Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Left) xdir = -1;
		if (e.key.code == Keyboard::Right) xdir = 1;
	}
	if (e.type == Event::KeyReleased) {
		if (e.key.code == Keyboard::Left) xdir = 0;
		if (e.key.code == Keyboard::Right) xdir = 0;
	}
}

void PlayerState::draw(sf::RenderWindow& window)
{
	playerSprite.updatePos(box.getPos());
	playerSprite.draw(window);
}

sf::Vector2i PlayerState::getDir()
{
	return sf::Vector2i(xdir,ydir);
}

void PlayerState::applyGravity(float delta)
{
	box.move(0, gravity * delta);
}
