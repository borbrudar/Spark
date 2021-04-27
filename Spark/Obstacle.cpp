#include "Obstacle.h"
using namespace sf;
Obstacle::Obstacle()
{
	box.setFillColor(Color::Green);
	box.setSize(Vector2f(150, 50));
	pos = Vector2f(200, 50);
}
void Obstacle::update(float delta, Vector2f scroll)
{
	Entity::update(delta, scroll);
}

void Obstacle::draw(sf::RenderWindow& window)
{
	window.draw(box);
}
