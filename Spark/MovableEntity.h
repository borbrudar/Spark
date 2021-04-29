#pragma once
#include "Entity.h"
#include "ImmovableEntity.h"

class MovableEntity : public Entity {
public:
	virtual void update(float delta,sf::Vector2f scroll) override;
	void resolveCollisionWithImmovable(ImmovableEntity &e);
private:
	sf::Vector2f prevPos;
};