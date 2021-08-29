#pragma once
#include "PlayerState.h"
#include "PlayerJumping.h"

class PlayerFalling : public PlayerJumping {
public:
	PlayerFalling() { vel.y = -jumpConst / 3; };
	std::unique_ptr<PlayerState> update(float delta) override;
};