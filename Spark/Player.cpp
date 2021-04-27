#include "Player.h"
using namespace sf;

Player::Player()
{
	box.setSize(Vector2f(50, 50));
}

void Player::handleInput(sf::Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Up) ydir = -1;
		if (e.key.code == Keyboard::Down) ydir = 1;
		if (e.key.code == Keyboard::Left) xdir = -1;
		if (e.key.code == Keyboard::Right) xdir = 1;
	}
	if (e.type == Event::KeyReleased) {
		if (e.key.code == Keyboard::Up) ydir = 0;
		else if (e.key.code == Keyboard::Down) ydir = 0;
		if (e.key.code == Keyboard::Left) xdir = 0;
		else if (e.key.code == Keyboard::Right) xdir = 0;
	}
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(box);
}

void Player::update(float delta, Vector2f scroll)
{
	Entity::update(delta, scroll);
}

void Player::resolveCollision()
{
	pos = prevPos;
}

Vector2i Player::getDir()
{
	return Vector2i(xdir,ydir);
}
