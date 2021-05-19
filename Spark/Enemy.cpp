#include "Enemy.h"
#include "Tile.h"

using namespace sf;

Enemy::Enemy()
{
	box = std::make_shared<AdvancedBox>();
	entityColor = Color::Blue;
}

void Enemy::createEntity(sf::Vector2f pos, sf::Vector2f size)
{
	Entity::createEntity(pos, size);
	advBox.create(pos, size);
}

void Enemy::update(float delta, sf::Vector2f scroll)
{
	Entity::update(delta, scroll);
	advBox.setPosition(pos);
	pos.x -= 30 * delta;
	if (!lastCol.bottom) pos.y += 90.f * delta;

	lastCol.reset();
}

void Enemy::specificCollision(Enemy& e)
{

}

void Enemy::specificCollision(Tile& t)
{
	lastCol += (advBox.checkCollision(t.getCollisionBox()));
}
