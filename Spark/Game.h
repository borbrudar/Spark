#pragma once
#include "GameState.h"
#include "Entity.h"
#include "Player.h"
#include "Obstacle.h"
#include <vector>


class Game : public GameState{
public:
	Game();

	void handleInput(sf::Event& e);
	void draw(sf::RenderWindow& window);
	void update(float delta);
private:
	Player player;
	std::vector<std::unique_ptr<Entity>> entities;
	double scrollSpeed = 250.f;
	sf::Vector2f scroll;
};