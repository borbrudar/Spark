#include "PlayerJumping.h"
#include "PlayerOnGround.h"

PlayerJumping::PlayerJumping()
{
    vel.y = jumpConst;
}

void PlayerJumping::handleInput(sf::Event& e)
{
    PlayerState::handleInput(e);
}

std::unique_ptr<PlayerState> PlayerJumping::update(float delta)
{
    PlayerState::updateBoxPosition();
    PlayerState::horizontalCollision();
    PlayerState::defaultResolveCollision();

    pos.y += vel.y * delta;
    vel.y += acc * delta;

    if (lastColType == collisionType::top) return std::make_unique<PlayerOnGround>();
    
    lastColType = collisionType::none;
    return nullptr;
}
