#include "Enemy.h"
#include "Tile.h"

using namespace sf;

Enemy::Enemy()
{
	box = std::make_shared<AdvancedBox>();
	entityColor = Color::Blue;
}

void Enemy::update(float delta)
{
	pos.x -= 30 * delta;
	if (!lastCol.bottom) pos.y += 90.f * delta;

	lastCol.reset();
}

void Enemy::specificCollision(Enemy& e)
{

}

void Enemy::specificCollision(Tile& t)
{
	lastCol += (box->checkCollision(*t.box));
}
