#include "PlayerOnGround.h"
#include "PlayerJumping.h"
#include "PlayerFalling.h"

using namespace sf;

void PlayerOnGround::handleInput(sf::Event& e)
{
	PlayerState::handleInput(e);
}

std::unique_ptr<PlayerState> PlayerOnGround::update(float delta)
{
	PlayerState::updateBoxPosition();
	if (ydir == 1) {
		clearState();
		return std::make_unique<PlayerJumping>();
	}
	if (lastColType != collisionType::top) {
		clearState();
		return std::make_unique<PlayerFalling>();
	}
	lastColType = collisionType::none;
	return nullptr;
}

void PlayerOnGround::clearState()
{
	ydir = 0;
	lastColType = collisionType::none;
}
