#pragma once
#include "PlayerState.h"
#include "PlayerJumping.h"

class PlayerFalling : public PlayerJumping {
public:
	PlayerFalling() { vel.y = -jumpConst / 3; };
};