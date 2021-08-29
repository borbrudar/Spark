#include "PlayerFalling.h"
#include "PlayerOnGround.h"

std::unique_ptr<PlayerState> PlayerFalling::update(float delta)
{
    PlayerState::basicBehaviour();
    PlayerJumping::positionUpdate(delta);

    if (lastColInfo.bottom)
        return std::make_unique<PlayerOnGround>();

    lastColInfo.reset();
    return nullptr;
}
