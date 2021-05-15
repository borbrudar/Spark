#include "Enemy.h"
#include "Tile.h"

using namespace sf;
Enemy::Enemy()
{
	ID = ID::enemy;
	pos = { 500,100 };
	box.create(pos, { 50,50 });
	temp.setSprite(pos, { 50,50 }, Color::Blue);
}

void Enemy::update(float delta, sf::Vector2f scroll)
{
	Entity::update(delta, scroll);
	pos.x -= 30 * delta;
}

void Enemy::specificCollision(Enemy& e)
{

}

void Enemy::specificCollision(Tile& t)
{
	lastCol.operator+=(box.checkCollision(t.getCollisionBox()));
}
