#include "Tile.h"
using namespace sf;

Tile::Tile(sf::Vector2f pos, sf::Vector2f size)
{
	this->pos = pos;
	this->size = size;
	temp.setSprite(pos, size, Color::Green);
	box.create(pos, size);
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

void Tile::drawPreview(Vector2f leftCorner, Vector2f rightCorner, RenderWindow &window)
{
	ISprite temp;
	Vector2f size = Vector2f(rightCorner.x - leftCorner.x,
		 rightCorner.y - leftCorner.y);
	temp.setSprite(leftCorner, size, Color::Red);
	temp.draw(window);
}

