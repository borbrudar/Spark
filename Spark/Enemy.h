#pragma once
#include "Entity.h"

class Enemy : public Entity {
public:
	Enemy();
	virtual void update(float delta, sf::Vector2f scroll) override;
};