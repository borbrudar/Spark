#pragma once
#include "Entity.h"

class VisualTile : public Entity {
public:
	virtual void createEntity(sf::Vector2f pos, sf::Vector2f size);
	virtual void update(float delta, sf::Vector2f scroll);
	virtual void draw(sf::RenderWindow& window);
};