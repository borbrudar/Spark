#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "CollisionInfo.h"

class CollisionBox {
public:
	void create(sf::Vector2f pos, sf::Vector2f size);
	void update(sf::Vector2f newPos);
	void draw(sf::RenderWindow& window);
	void defaultResolveCollision();
	collisionType checkCollision(CollisionBox& other);
private:
	std::vector<sf::RectangleShape> box;
	sf::Vector2f pos, size, prevPos;
};