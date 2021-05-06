#pragma once
#include <vector>
#include "GameState.h"


class PlayState : public GameState{
public:
	PlayState();
	PlayState(SharedGameState& s);
	void handleInput(sf::Event& e);
	void update(float delta);
private:
	void checkCollision(float delta);
};