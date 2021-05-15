#pragma once
#include "Entity.h"

class Tile;

class Enemy : public Entity {
public:
	Enemy();
	virtual void update(float delta, sf::Vector2f scroll) override; 
	void checkCollision(Entity& e) override { e.specificCollision(*this); };
private:
	void specificCollision(Enemy& e) override;
	void specificCollision(Tile& t) override;
	collisionInfo lastCol = collisionInfo();
};