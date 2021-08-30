#include "MovableEntity.h"

void MovableEntity::update(float delta, sf::Vector2f scroll)
{
	pos.y += gravity * delta;
}
