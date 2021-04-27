#include "Player.h"
using namespace sf;

Player::Player()
{
	shape.setFillColor(Color::Red);
	shape.setSize(Vector2f(50, 50));
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
	window.draw(shape);
}

void Player::update(float delta)
{
	pos = shape.getPosition();
	vel.x = xdir * speed;
	vel.y = ydir * speed;
	pos += vel * delta;
	shape.setPosition(pos);
}
