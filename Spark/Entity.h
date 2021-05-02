#pragma once
#include <SFML/Graphics.hpp>
#include "ISprite.h"

class Entity {
public:
	Entity() = default;
	//adds scrolling and sprite update
	virtual void update(float delta, sf::Vector2f scroll);
	virtual void draw(sf::RenderWindow& window);
protected:
	ISprite temp;
	sf::Vector2f pos{ 0, 0}, vel;
};