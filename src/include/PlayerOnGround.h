#pragma once
#include "PlayerState.h"

class PlayerOnGround : public PlayerState {
public:
	PlayerOnGround() = default;
	virtual void handleInput(sf::Event& e) override;
	virtual std::unique_ptr<PlayerState> update(float delta, sf::Vector2f scroll) override;
};