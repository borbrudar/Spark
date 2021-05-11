#include "Entity.h"
using namespace sf;

void Entity::update(float delta, Vector2f scroll)
{
	pos += scroll * delta;
	temp.updatePos(pos);
	box.setPosition(pos);
}

void Entity::draw(sf::RenderWindow& window)
{
	temp.draw(window);
}

CollisionBox& Entity::getCollisionBox()
{
	return box;
}
