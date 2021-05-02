#pragma once
#include "PlayerState.h"

class PlayerJumping : public PlayerState {
public:
	PlayerJumping();
	PlayerJumping(sf::Vector2f pos);
	virtual void handleInput(sf::Event& e) override;
	virtual std::unique_ptr<PlayerState> update(float delta) override;
private:
	const float jumpConst = -600.f, acc = 900.f; //todo acc with *0.98 or ...?
};