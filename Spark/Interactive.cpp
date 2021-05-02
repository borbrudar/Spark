#include "Interactive.h"

void Interactive::update(float delta, sf::Vector2f scroll)
{
	box.setPosition(pos);
}

CollisionBox& Interactive::getCollisionBox()
{
	return box;
}
