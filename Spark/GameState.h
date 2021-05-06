#pragma once
#include "Entity.h"
#include "Player.h"
#include "Tile.h"
#include "Enemy.h"

struct SharedGameState {
	Player player;
	std::vector<std::unique_ptr<Tile>> tiles;
	std::vector<std::unique_ptr<Enemy>> enemies;
};

class GameState {
public:
	virtual void handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window) = 0;
	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderWindow& window);
	SharedGameState& getState();
protected:
	SharedGameState ss;
	double scrollSpeed = 250.f;
	sf::Vector2f scroll;
};