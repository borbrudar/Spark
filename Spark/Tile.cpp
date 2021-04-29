#include "Tile.h"
using namespace sf;
Tile::Tile()
{
	box.setFillColor(Color::Green);
	box.setSize(Vector2f(150, 50));
	pos = Vector2f(200, 350);
}
void Tile::update(float delta, Vector2f scroll)
{
	Entity::update(delta, scroll);
}

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(box);
}
