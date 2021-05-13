#pragma once
#include "Entity.h"
#include "Player.h"
#include "Tile.h"
#include "Enemy.h"
#include "LevelReader.h"

const int tileSize = 50;
struct SharedGameState {
	Player player;
	std::vector<std::unique_ptr<Entity>> tiles;
	std::vector<std::unique_ptr<Enemy>> enemies;
	LevelReader level = LevelReader(tileSize);
	sf::Vector2i totalScroll;
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
	SharedGameState ss;
	sf::Vector2f scroll;
};