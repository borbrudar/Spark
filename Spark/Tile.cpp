#include "Tile.h"
using namespace sf;
Tile::Tile()
{
	pos = Vector2f(200, 350);
	temp.setSprite(pos, { 150,50 }, Color::Green);
	box.create(pos, { 150,50 });
}

void Tile::update(float delta, Vector2f scroll)
{
	Entity::update(delta, scroll);
	box.setPosition(pos);
}

