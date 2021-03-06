#pragma once
#include "GameState.h"
#include "EditorSidebar.h"

class Editor : public GameState {
public:
	Editor() = default;
	Editor(SharedGameState& s);
	void handleInput(sf::Event& e, sf::Mouse &m, sf::RenderWindow& window) final;
	void draw(sf::RenderWindow& window) final;
	void update(float delta) final;
private:
	void addBlocks(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window);
	void removeBlocks(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window);
	sf::Vector2i startPos, endPos, deltaPos;
	bool drawPreview = 0;
	EditorSidebar sidebar;
};