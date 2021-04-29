#pragma once
#include "MovableEntity.h"

class Enemy : public MovableEntity {
public:
	Enemy();
	virtual void update(float delta, sf::Vector2f scroll) override;
};