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
	void checkCollision(float delta);

	Player player;
	std::vector<std::unique_ptr<Obstacle>> tiles;
	double scrollSpeed = 250.f;
	sf::Vector2f scroll;
};