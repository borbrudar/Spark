#pragma once
#include "Interactive.h"
#include "CollisionBox.h"

class MovableEntity : public Interactive {
public:
	virtual void update(float delta,sf::Vector2f scroll) override;
protected:
	CollisionBox box;
	float speed = 250.f, gravity = 50.f;
	const float constGravity = 50.f, constSpeed = 250.f;
};