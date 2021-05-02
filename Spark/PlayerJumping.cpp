#include "PlayerJumping.h"
#include "PlayerOnGround.h"

PlayerJumping::PlayerJumping()
{
    vel.y = jumpConst;
}

PlayerJumping::PlayerJumping(sf::Vector2f pos)
{
    vel.y = jumpConst;
    this->pos = pos;
}

void PlayerJumping::handleInput(sf::Event& e)
{
    PlayerState::handleInput(e);
}

std::unique_ptr<PlayerState> PlayerJumping::update(float delta)
{
    PlayerState::updateBoxPosition();
    //applyGravity(delta);
    ydir = 0;
    
    pos.y += vel.y * delta;
    vel.y += acc * delta;

    if (lastColType == collisionType::top) {
        return std::make_unique<PlayerOnGround>(pos);
    }
    
    return nullptr;
}
