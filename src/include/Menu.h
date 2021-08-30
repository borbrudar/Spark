#pragma once
#include "State.h"

class Menu : public State {
public:
	void handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void update(float delta);
};