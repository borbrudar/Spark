#include "Tile.h"
using namespace sf;

Tile::Tile(sf::Vector2f pos)
{
	this->pos = pos;
	this->size = { 150,50 };
	temp.setSprite(pos, size, Color::Green);
	box.create(pos, size );
}

void Tile::update(float delta, Vector2f scroll)
{
	Entity::update(delta, scroll);
	box.setPosition(pos);
}

void Tile::draw(sf::RenderWindow& window)
{
	box.draw(window);
}

