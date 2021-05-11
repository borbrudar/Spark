#include "Player.h"
using namespace sf;

Player::Player()
{
	playerState = std::make_unique<PlayerFalling>();
}

void Player::handleInput(sf::Event& e)
{
	playerState->handleInput(e);
}

void Player::update(float delta)
{
	auto temp = playerState->update(delta);
	if (temp) {
		playerState = std::move(temp);
	}
}

void Player::draw(sf::RenderWindow& window)
{
	playerState->draw(window);
}

void Player::checkCollision(Entity& e)
{
	playerState->checkCollision(e);
}

Vector2i Player::getDir()
{
	return playerState->getDir();
}
