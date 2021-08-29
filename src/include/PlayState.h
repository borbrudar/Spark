#pragma once
#include "GameState.h"
#include <vector>


class PlayState : public GameState{
public:
	PlayState();
	PlayState(SharedGameState& s);
	void handleInput(sf::Event& e);
	void update(float delta);
private:
	void checkCollision(float delta);
};