#pragma once
#include <SFML/Graphics.hpp>
#include "ISprite.h"
#include "CollisionBox.h"
#include "ID.h"
#include <iostream>


class Enemy;
class Tile;

class Entity {
public:
	Entity() = default;
	virtual void createEntity(sf::Vector2f pos, sf::Vector2f size);
	//adds scrolling and sprite update
	virtual void update(float delta, sf::Vector2f scroll);
	virtual void draw(sf::RenderWindow& window); 
	virtual void checkCollision(Entity& e) {};

	virtual void specificCollision(Tile& t) {};
	virtual void specificCollision(Enemy& e) {};

	void inline defaultResolveCollision(Entity& i) {
		box->checkCollision(*i.box);
	}
	CollisionBox& getCollisionBox();

	void setPixelPos(sf::Vector2i pos);
	sf::Vector2i getPixelPos();
protected:
	ID ID;
	std::shared_ptr<CollisionBox> box;
	ISprite temp;
	sf::Vector2f pos{ 0, 0 }, vel, size;
	sf::Vector2i pixelPos;
	sf::Color entityColor = sf::Color(255, 192, 203);
};