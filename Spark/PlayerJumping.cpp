#include "PlayerJumping.h"

void PlayerJumping::handleInput(sf::Event& e)
{
    return PlayerState::handleInput(e);
}

std::unique_ptr<PlayerState> PlayerJumping::update(float delta)
{
    applyGravity(delta);
    return nullptr;
}
