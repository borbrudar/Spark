#pragma once
#include "GameState.h"

class Editor : public GameState {
public:
	Editor() = default;
	Editor(SharedGameState& s);
	void handleInput(sf::Event& e, sf::Mouse &m, sf::RenderWindow& window) final;
	void draw(sf::RenderWindow& window) final;
	void update(float delta) final;
private:
	void addBlocks(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window);
	sf::Vector2f startPos, endPos, clampedPos;
	bool drawPreview = 0;
};