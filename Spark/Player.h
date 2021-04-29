#pragma once
#include <SFML/Graphics.hpp>
#include "MovableEntity.h"

class Player : public MovableEntity {
public:
	Player();
	void handleInput(sf::Event& e);
	void draw(sf::RenderWindow& window);
	void update(float delta, sf::Vector2f scroll) override;
	sf::Vector2i getDir();
private:
	int xdir = 0, ydir = 0;
	float speed = 250.f, gravity = 45.f;
};