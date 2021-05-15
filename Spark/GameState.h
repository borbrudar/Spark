#pragma once
#include "Entity.h"
#include "Player.h"
#include "Tile.h"
#include "Enemy.h"
#include "LevelReader.h"

struct SharedGameState {
	Player player;
	std::vector<std::unique_ptr<Entity>> entities;
	LevelReader level;
	sf::Vector2f totalScroll;
};

class GameState {
public:
	GameState();
	virtual ~GameState() {};
	virtual void handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window) = 0;
	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderWindow& window);
	SharedGameState& getState();
protected:
	double scrollSpeed = 250.f;
	const int tileSize = LevelReader::tileSize;
	SharedGameState ss;
	sf::Vector2f scroll;
};