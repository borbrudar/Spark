#include "Enemy.h"
using namespace sf;
Enemy::Enemy()
{
	box.setFillColor(Color::Blue);
	box.setSize({ 50, 50 });
	pos = { 500,100 };
}

void Enemy::update(float delta, sf::Vector2f scroll)
{
	Entity::update(delta, scroll);
	MovableEntity::update(delta, scroll);
	pos.x -= 30 * delta;
}
