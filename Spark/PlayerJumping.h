#pragma once
#include "PlayerState.h"

class PlayerJumping : public PlayerState {
public:
	virtual void handleInput(sf::Event& e) override;
	virtual std::unique_ptr<PlayerState> update(float delta) override;
};