#pragma once
#include "State.h"
#include "GameState.h"
#include "PlayState.h"
#include "Editor.h"


class Game : public State {
public:
	Game();
	virtual void handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float delta);

	std::unique_ptr<GameState> gameState;
};