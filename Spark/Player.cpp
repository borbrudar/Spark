#include "Player.h"
using namespace sf;

Player::Player()
{
	playerState = std::make_unique<PlayerJumping>();
	box.setSize(Vector2f(50, 50));
	pos = { 100,200 };
}

void Player::handleInput(sf::Event& e)
{
	playerState->handleInput(e);
}

void Player::update(float delta, Vector2f scroll)
{
	Entity::update(delta, scroll);
	MovableEntity::update(delta, scroll);
}

Vector2i Player::getDir()
{
	return playerState->getDir();
}
