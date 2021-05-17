#include "Tile.h"
using namespace sf;

Tile::Tile()
{
	entityColor = Color::Green;
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

void Tile::checkCollision(Entity& e)
{
	e.specificCollision(*this);
}

void Tile::drawPreview(Vector2f leftCorner, Vector2f rightCorner, RenderWindow &window)
{
	ISprite temp;
	Vector2f size = Vector2f(rightCorner.x - leftCorner.x,
		 rightCorner.y - leftCorner.y);
	temp.setSprite(leftCorner, size, Color(34, 139, 34));
	temp.draw(window);
}

