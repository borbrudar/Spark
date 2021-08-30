#pragma once
#include "Entity.h"

class Tile : public Entity {
public:
	Tile();
	void update(float delta) override;
	void draw(sf::RenderWindow& window) override;
	void checkCollision(Entity& e) override;

	static void drawPreview(sf::Vector2f leftCorner,sf::Vector2f rightCorner, sf::RenderWindow &window);
private:
};