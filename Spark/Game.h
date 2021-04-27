#pragma once
#include "GameState.h"
#include "Player.h"


class Game : public GameState{
public:
	Game();

	void handleInput(sf::Event& e);
	void draw(sf::RenderWindow& window);
	void update(float delta);
private:
	Player player;
};