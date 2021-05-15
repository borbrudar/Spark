#include "Enemy.h"
#include "Tile.h"

using namespace sf;

Enemy::Enemy(Vector2f pos, Vector2f size)
{
	this->pos = pos;
	ID = ID::enemy;
	box.create(pos, size);
	advBox.create(pos, size);
	temp.setSprite(pos, size, Color::Blue);
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
