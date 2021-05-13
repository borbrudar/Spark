#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class LevelReader {
public:
	LevelReader() = default;
	void loadLevel(std::string path, std::vector<std::unique_ptr<Entity>>& vec, int tileSize);
	void addBlock(sf::Color c, sf::Vector2f pos, sf::Vector2f scroll, sf::Vector2f size);

	static sf::Vector2i toTileCoords(sf::Vector2i vec, sf::Vector2i offset = { 0,0 });
	static sf::Vector2i clampToWorldCoords(sf::Vector2i vec, sf::Vector2i offset = { 0,0});
	static int toTileCoords(float x, int offset = 0);
	static int clampToWorldCoords(float x, int offset = 0);
	static int tileSize;
private:
	std::unique_ptr<Entity> checkType(sf::Color c, int x, int y);
	sf::Image level;
};
