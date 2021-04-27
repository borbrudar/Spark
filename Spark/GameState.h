#pragma once
#include <SFML/Graphics.hpp>


class GameState {
public:
	virtual void handleInput(sf::Event &e) = 0;
	virtual void draw(sf::RenderWindow& window)  = 0;
	virtual void update(float delta) = 0;
};