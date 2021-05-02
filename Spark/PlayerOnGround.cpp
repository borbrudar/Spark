#include "PlayerOnGround.h"
#include "PlayerJumping.h"

using namespace sf;
void PlayerOnGround::handleInput(sf::Event& e)
{
	PlayerState::handleInput(e);
}

std::unique_ptr<PlayerState> PlayerOnGround::update(float delta)
{
	return nullptr;
}
