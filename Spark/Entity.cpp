#include "Entity.h"
using namespace sf;
Entity::Entity()
{
	box.setFillColor(Color::Red);
}

bool Entity::overlaps(const Entity& other)
{
	return box.getGlobalBounds().intersects(other.box.getGlobalBounds());
}

void Entity::update(float delta, Vector2f scroll)
{
	pos += scroll * delta;
	box.setPosition(pos);
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(box);
}

sf::FloatRect Entity::getBoxBounds()
{
	return box.getGlobalBounds();
}

