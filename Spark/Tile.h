#pragma once
#include "ImmovableEntity.h"

class Tile : public ImmovableEntity {
public:
	Tile(sf::Vector2f pos, sf::Vector2f size = { 150,50 });
	void update(float delta, sf::Vector2f scroll) override;
	void draw(sf::RenderWindow& window) override;
	static void drawPreview(sf::Vector2f leftCorner,sf::Vector2f rightCorner, sf::RenderWindow &window);
private:
	sf::Vector2f size;
};