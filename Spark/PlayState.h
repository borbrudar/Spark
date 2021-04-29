#pragma once
#include <vector>
#include "State.h"
#include "Entity.h"
#include "Player.h"
#include "Tile.h"
#include "Enemy.h"


class PlayState : public State{
public:
	PlayState();

	void handleInput(sf::Event& e);
	void draw(sf::RenderWindow& window);
	void update(float delta);
private:
	void checkCollision(float delta);

	Player player;
	std::vector<std::unique_ptr<Tile>> tiles;
	std::vector<std::unique_ptr<Enemy>> enemies;
	double scrollSpeed = 250.f;
	sf::Vector2f scroll;
};