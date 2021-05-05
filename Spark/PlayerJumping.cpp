#include "PlayerJumping.h"
#include "PlayerOnGround.h"
#include "PlayerFalling.h"

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
    PlayerState::basicBehaviour();
    positionUpdate(delta);
    
    if (lastColInfo.bottom) 
        return std::make_unique<PlayerOnGround>();
    if (lastColInfo.top)
        return std::make_unique<PlayerFalling>();
    
    lastColInfo.reset();
    return nullptr;
}

void PlayerJumping::positionUpdate(float delta)
{
    pos.y += vel.y * delta;
    vel.y += acc * delta;
}
