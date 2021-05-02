#pragma once
#include "PlayerState.h"

class PlayerOnGround : public PlayerState {
public:
	virtual void handleInput(sf::Event& e) override;
	virtual std::unique_ptr<PlayerState> update(float delta) override;
};