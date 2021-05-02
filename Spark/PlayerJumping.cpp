#include "PlayerJumping.h"
#include "PlayerOnGround.h"

void PlayerJumping::handleInput(sf::Event& e)
{
    PlayerState::handleInput(e);
}

std::unique_ptr<PlayerState> PlayerJumping::update(float delta)
{
    applyGravity(delta);
    if (lastColType == collisionType::top) return std::make_unique<PlayerOnGround>();

    return nullptr;
}
