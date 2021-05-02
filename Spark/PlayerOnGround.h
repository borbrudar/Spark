#pragma once
#include "PlayerState.h"

class PlayerOnGround : public PlayerState {
public:
	PlayerOnGround() = default;
	PlayerOnGround(sf::Vector2f pos); //TODO payload class to transfer data between states
	virtual void handleInput(sf::Event& e) override;
	virtual std::unique_ptr<PlayerState> update(float delta) override;
};