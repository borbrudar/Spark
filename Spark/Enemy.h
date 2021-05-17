#pragma once
#include "Entity.h"
#include "AdvancedBox.h"

class Tile;

class Enemy : public Entity {
public:
	Enemy();
	virtual void createEntity(sf::Vector2f pos, sf::Vector2f size) override;
	virtual void update(float delta, sf::Vector2f scroll) override; 
	void checkCollision(Entity& e) override { e.specificCollision(*this); };
private:
	void specificCollision(Enemy& e) override;
	void specificCollision(Tile& t) override;
	collisionInfo lastCol = collisionInfo();
	AdvancedBox advBox;
};