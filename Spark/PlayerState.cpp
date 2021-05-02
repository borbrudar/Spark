#include "PlayerState.h"
using namespace sf;
PlayerState::PlayerState()
{
	box.create(pos, size);
	playerSprite.setSprite(pos, size, Color::Red);
}
void PlayerState::handleInput(sf::Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Left) xdir = -1;
		if (e.key.code == Keyboard::Right) xdir = 1;
		if (e.key.code == Keyboard::Up) {
			ydir = 1;
		}
	}
	if (e.type == Event::KeyReleased) {
		if (e.key.code == Keyboard::Left) xdir = 0;
		if (e.key.code == Keyboard::Right) xdir = 0;
	}
}

void PlayerState::draw(sf::RenderWindow& window)
{
	playerSprite.updatePos(pos);
	playerSprite.draw(window);
}

void PlayerState::checkCollision(Interactive& e)
{
	collisionType temp = box.checkCollision(e.getCollisionBox());
	if (temp != collisionType::none) {
		lastColType = temp;
		lastCol = std::make_unique<Interactive>(e);
	}
}

sf::Vector2i PlayerState::getDir()
{
	return sf::Vector2i(xdir,0);
}

void PlayerState::applyGravity(float delta)
{
	pos.y += gravity * delta;
}

void PlayerState::updateBoxPosition()
{
	box.setPosition(pos);
}
