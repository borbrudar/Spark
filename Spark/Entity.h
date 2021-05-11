#pragma once
#include <SFML/Graphics.hpp>
#include "ISprite.h"
#include "CollisionBox.h"
#include "ID.h"

class Entity {
public:
	Entity() = default;
	//adds scrolling and sprite update
	virtual void update(float delta, sf::Vector2f scroll);
	virtual void draw(sf::RenderWindow& window); 
	
	void inline defaultResolveCollision(Entity& i) {
		box.checkCollision(i.box);
	}
	CollisionBox& getCollisionBox();
protected:
	ID ID;
	CollisionBox box;
	ISprite temp;
	sf::Vector2f pos{ 0, 0}, vel;
};