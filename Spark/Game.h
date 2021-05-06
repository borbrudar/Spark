#pragma once
#include "GameState.h"
#include "PlayState.h"
#include "Editor.h"


class Game : public State {
public:
	Game();
	virtual void handleInput(sf::Event& e);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float delta);

	std::unique_ptr<GameState> gameState;
};