#include "PlayerOnGround.h"
#include "PlayerJumping.h"

using namespace sf;
PlayerOnGround::PlayerOnGround(sf::Vector2f pos)
{
	this->pos = pos;
}
void PlayerOnGround::handleInput(sf::Event& e)
{
	PlayerState::handleInput(e);
}

std::unique_ptr<PlayerState> PlayerOnGround::update(float delta)
{
	PlayerState::updateBoxPosition();
	if (ydir == 1) {
		ydir = 0;
		return std::make_unique<PlayerJumping>(pos);
	}
	return nullptr;
}
