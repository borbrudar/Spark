#pragma once
#include "GameState.h"

class Game : public GameState{
public:
	void handleInput(sf::Event& e);
	void draw(sf::RenderWindow& window);
	void update(float delta);
};