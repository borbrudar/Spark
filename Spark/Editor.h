#pragma once
#include "State.h"

class Editor : public State {
public:
	Editor() = default;
	virtual void handleInput(sf::Event& e);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float delta);
};