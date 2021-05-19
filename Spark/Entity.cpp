#include "Entity.h"
using namespace sf;

void Entity::createEntity(sf::Vector2f pos, sf::Vector2f size)
{
	this->pos = pos;
	this->size = size;
	temp.setSprite(pos, size, entityColor);
	box->create(pos, size);
}

void Entity::update(float delta, Vector2f scroll)
{
	pos += scroll * delta;
	temp.updatePos(pos);
	box->setPosition(pos);
}

void Entity::draw(sf::RenderWindow& window)
{
	temp.draw(window);
}

CollisionBox& Entity::getCollisionBox()
{
	return *box;
}

void Entity::setPixelPos(sf::Vector2i pos)
{
	pixelPos = pos;
}

sf::Vector2i Entity::getPixelPos()
{
	return pixelPos;
}
