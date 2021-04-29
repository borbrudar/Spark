#include "MovableEntity.h"

void MovableEntity::update(float delta, sf::Vector2f scroll)
{
	prevPos = pos;
}

void MovableEntity::resolveCollisionWithImmovable(ImmovableEntity &e)
{
	if(box.getGlobalBounds().intersects(e.getBoxBounds()))
		pos = prevPos;
}
