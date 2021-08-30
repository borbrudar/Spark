#include "PlayerOnGround.h"
#include "PlayerJumping.h"
#include "PlayerFalling.h"

using namespace sf;

void PlayerOnGround::handleInput(sf::Event& e)
{
	PlayerState::handleInput(e);
}

std::unique_ptr<PlayerState> PlayerOnGround::update(float delta, sf::Vector2f scroll)
{
	unscroll(scroll);
	PlayerState::basicBehaviour();

	if (ydir == 1) {
		lastColInfo.reset();
		return std::make_unique<PlayerJumping>();
	}
	if (lastColInfo.isNoCollision()) {
		lastColInfo.reset();
		return std::make_unique<PlayerFalling>();
	}
	lastColInfo.reset();
	return nullptr;
}

