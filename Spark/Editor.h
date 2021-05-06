#pragma once
#include "GameState.h"

class Editor : public GameState {
public:
	Editor() = default;
	Editor(SharedGameState& s);
	virtual void handleInput(sf::Event& e, sf::Mouse &m, sf::RenderWindow& window);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float delta);
private:
	sf::Vector2i startPos, endPos;
	bool drawPreview = 0;
};