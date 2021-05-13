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
	sf::Vector2i startPos, endPos;
	bool drawPreview = 0;
};