#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
	Entity();
	bool overlaps(const Entity& other);
	virtual void update(float delta, sf::Vector2f scroll);
	virtual void draw(sf::RenderWindow& window) = 0;
	sf::FloatRect getBoxBounds();
protected:
	sf::RectangleShape box;
	sf::Vector2f pos{ 0, 0}, vel;
};