#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class PlayerState {
public:
	virtual std::unique_ptr<PlayerState> handleInput(sf::Event& e);
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(float delta, sf::Vector2f scroll, Player& p) = 0;
	sf::Vector2i getDir();
protected:
	int xdir = 0, ydir = 0;
};