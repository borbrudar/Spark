#pragma once
#include "Entity.h"

class Obstacle : public Entity {
public:
	Obstacle();
	void update(float delta, sf::Vector2f scroll) override;
	void draw(sf::RenderWindow& window) override;
};