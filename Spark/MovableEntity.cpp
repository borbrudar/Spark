#include "MovableEntity.h"

void MovableEntity::update(float delta, sf::Vector2f scroll)
{
	prevPos = pos;
	pos.y += gravity * delta;
}

void MovableEntity::resolveCollisionWithImmovable(ImmovableEntity &e)
{
	if(box.getGlobalBounds().intersects(e.getBoxBounds()))
		pos = prevPos;
}
