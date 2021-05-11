#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class LevelReader {
public:
	LevelReader() = default;
	void loadLevel(std::string path, std::vector<std::unique_ptr<Entity>>& vec, int tileSize);
private:
	std::unique_ptr<Entity> checkType(sf::Color c, int x, int y);
	sf::Image level;
	int tileSize = 20;
};
