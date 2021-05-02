#include "Player.h"
using namespace sf;

Player::Player()
{
	playerState = std::make_unique<PlayerJumping>();
}

void Player::handleInput(sf::Event& e)
{
	playerState->handleInput(e);
}

void Player::update(float delta)
{
	playerState->update(delta);
}

void Player::draw(sf::RenderWindow& window)
{
	playerState->draw(window);
}

Vector2i Player::getDir()
{
	return playerState->getDir();
}
