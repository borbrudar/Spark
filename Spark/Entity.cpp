#include "Entity.h"
using namespace sf;

void Entity::createEntity(sf::Vector2f pos, sf::Vector2f size)
{
	this->pos = pos;
	this->size = size;
	temp.setSprite(pos, size, entityColor);
	box->create(pos, size);
}

void Entity::update(float delta)
{
}

void Entity::draw(sf::RenderWindow& window)
{
	temp.draw(window);
}

void Entity::setPixelPos(sf::Vector2i pos)
{
	pixelPos = pos;
}

sf::Vector2i Entity::getPixelPos()
{
	return pixelPos;
}
