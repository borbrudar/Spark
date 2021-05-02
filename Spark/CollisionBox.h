#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ID.h"

enum class collisionType {
	none,
	left,
	right,
	top,
	bottom
};

class CollisionBox {
public:
	void create(sf::Vector2f pos, sf::Vector2f size);
	void update(sf::Vector2f newPos);
	void draw(sf::RenderWindow& window);
	void defaultResolveCollision();
	void move(sf::Vector2f by);
	void move(float x, float y) { move(sf::Vector2f(x, y)); };
	collisionType checkCollision(CollisionBox& other);
	sf::Vector2f getPos();
private:
	void updateBoxes();
	std::vector<sf::RectangleShape> box;
	sf::Vector2f pos, size, prevPos;
};