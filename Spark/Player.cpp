#include "Player.h"
using namespace sf;

Player::Player()
{
	ID = ID::player;
	playerState = std::make_unique<PlayerJumping>();
	pos = { 100,200 };
	box.create(pos, { 50,50 });
	temp.setSprite(pos, { 50,50 }, Color::Red);
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
