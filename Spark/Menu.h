#pragma once
#include "State.h"

class Menu : public State {
public:
	void handleInput(sf::Event& e, sf::Mouse& m);
	void draw(sf::RenderWindow& window);
	void update(float delta);
};