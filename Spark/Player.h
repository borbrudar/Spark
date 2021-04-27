#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player();
	void handleInput(sf::Event& e);
	void draw(sf::RenderWindow& window);
	void update(float delta);
private:
	sf::RectangleShape shape;
	int xdir = 0, ydir = 0;
	sf::Vector2f pos, vel;
	float speed = 250.f;
};