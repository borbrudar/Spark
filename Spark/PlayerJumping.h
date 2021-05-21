#pragma once
#include "PlayerState.h"

class PlayerJumping : public PlayerState {
public:
	PlayerJumping();
	virtual void handleInput(sf::Event& e) override;
	virtual std::unique_ptr<PlayerState> update(float delta, sf::Vector2f scroll) override;
protected:
	void positionUpdate(float delta);
	const float jumpConst = -600.f, acc = 900.f; //todo acc with *0.98 or ...?
};