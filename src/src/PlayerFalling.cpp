#include "PlayerFalling.h"
#include "PlayerOnGround.h"

std::unique_ptr<PlayerState> PlayerFalling::update(float delta, sf::Vector2f scroll)
{
    unscroll(scroll);
    PlayerState::basicBehaviour();
    PlayerJumping::positionUpdate(delta);

    if (lastColInfo.bottom) {
        defaultResolveCollision();
        return std::make_unique<PlayerOnGround>();
    }
    lastColInfo.reset();
    return nullptr;
}
