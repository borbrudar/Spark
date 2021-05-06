#pragma once
#include <vector>
#include "GameState.h"


class PlayState : public GameState{
public:
	PlayState();
	PlayState(SharedGameState& s);
	virtual void handleInput(sf::Event& e) override;
	virtual void update(float delta) override;
	virtual void setMouse(sf::RenderWindow& window) override;
private:
	void checkCollision(float delta);
};