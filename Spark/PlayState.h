#pragma once
#include <vector>
#include "GameState.h"


class PlayState : public GameState{
public:
	PlayState();
	PlayState(SharedGameState& s);
	virtual void handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window) override;
	virtual void update(float delta) override;
private:
	void checkCollision(float delta);
};