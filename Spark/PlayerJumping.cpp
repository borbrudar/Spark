#include "PlayerJumping.h"

std::unique_ptr<PlayerState> PlayerJumping::handleInput(sf::Event& e)
{
    return PlayerState::handleInput(e);
}

void PlayerJumping::draw(sf::RenderWindow& window)
{
}

void PlayerJumping::update(float delta, sf::Vector2f scroll, CollisionInfo &info)
{
}
