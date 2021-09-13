#include "VisualTile.h"

void VisualTile::createEntity(sf::Vector2f pos, sf::Vector2f size)
{
	this->pos = pos;
	this->size = size;
	temp.setSprite(pos, size, entityColor);
}

void VisualTile::update(float delta, sf::Vector2f scroll)
{
	pos += scroll * delta;
	temp.updatePos(pos);
}

void VisualTile::draw(sf::RenderWindow& window)
{
	temp.draw(window);
}
