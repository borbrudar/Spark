#pragma once
#include "ImmovableEntity.h"

class Tile : public ImmovableEntity {
public:
	Tile();
	Tile(sf::Vector2f pos);
	void update(float delta, sf::Vector2f scroll) override;
	void draw(sf::RenderWindow& window) override;
private:
	sf::Vector2f size;
};