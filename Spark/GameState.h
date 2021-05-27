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
	sf::Vector2f totalScroll, loadScroll;
	sf::View gameView = sf::View(sf::FloatRect(0.f,0.f, 640.f, 480.f));
	sf::View editorView = sf::View(sf::FloatRect(0.f, 0.f, 640.f, 480.f));
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
	void scrollInput(sf::Event& e);
	void updateScroll(float delta);
	double scrollSpeed = 250.f;
	const int tileSize = LevelReader::tileSize;
	SharedGameState ss;
	sf::Vector2f scroll;
	int xdir = 0, ydir = 0;
};