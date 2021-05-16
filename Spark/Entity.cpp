#include "Entity.h"
using namespace sf;

void Entity::update(float delta, Vector2f scroll)
{
	pos += scroll;
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

void Entity::setPixelPos(sf::Vector2i pos)
{
	pixelPos = pos;
}

sf::Vector2i Entity::getPixelPos()
{
	return pixelPos;
}

void Entity::setPos(sf::Vector2f pos)
{
	this->pos = pos;
}

sf::Vector2f Entity::getPos()
{
	return pos;
}
