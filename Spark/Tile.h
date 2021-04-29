#pragma once
#include "ImmovableEntity.h"

class Tile : public ImmovableEntity {
public:
	Tile();
	void update(float delta, sf::Vector2f scroll) override;
	void draw(sf::RenderWindow& window) override;
};