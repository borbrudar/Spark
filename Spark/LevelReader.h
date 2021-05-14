#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class LevelReader {
public:
	LevelReader(int tileSize) : tileSize(tileSize) {};
	void loadLevel(std::string path, std::vector<std::unique_ptr<Entity>>& vec, int tileSize);
	void addBlock(sf::Color c, sf::Vector2i pos, sf::Vector2i scroll, sf::Vector2i size);
private:
	std::unique_ptr<Entity> checkType(sf::Color c, int x, int y);
	sf::Image level;
	int tileSize;
};
