#pragma once
#include "Entity.h"
#include "ImmovableEntity.h"

class MovableEntity : public Entity {
public:
	virtual void update(float delta,sf::Vector2f scroll) override;
	void resolveCollisionWithImmovable(ImmovableEntity &e);
protected:
	sf::Vector2f prevPos;
	float speed = 250.f, gravity = 45.f;
};