#pragma once
#include "PlayerState.h"

class PlayerOnGround : public PlayerState {
public:
	virtual std::unique_ptr<PlayerState> handleInput(sf::Event& e);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float delta, sf::Vector2f scroll, Player& p);
};