#include "Entity.h"
using namespace sf;
Entity::Entity()
{
}

void Entity::update(float delta, Vector2f scroll)
{
	pos += scroll * delta;
}

void Entity::draw(sf::RenderWindow& window)
{
	temp.draw(window);
}
