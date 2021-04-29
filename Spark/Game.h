#pragma once
#include "State.h"
#include "Entity.h"
#include "Player.h"
#include "Tile.h"
#include <vector>


class Game : public State{
public:
	Game();

	void handleInput(sf::Event& e);
	void draw(sf::RenderWindow& window);
	void update(float delta);
private:
	void checkCollision(float delta);

	Player player;
	std::vector<std::unique_ptr<Tile>> tiles;
	double scrollSpeed = 250.f;
	sf::Vector2f scroll;
};