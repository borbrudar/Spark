#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class LevelReader {
public:
	LevelReader() = default;
	void loadLevel(const std::string path, std::vector<std::unique_ptr<Entity>>& vec,const sf::RenderWindow &window, sf::Vector2i tile = { 3,5 });
	void addBlock(sf::Color c, sf::Vector2i pos, sf::Vector2i scroll, sf::Vector2i size);
	void removeBlock(sf::Vector2i pos, sf::Vector2i scroll);

	static sf::Vector2i clampToTile(sf::Vector2i pos, sf::Vector2i offset = { 0,0 });
	static sf::Vector2i toTileCoords(sf::Vector2i pos, sf::Vector2i offset = { 0,0 });
	static int clampToTile(int pos, int offset = 0);
	static int toTileCoords(int pos, int offset = 0);
	bool getLoaded();

	static const int tileSize = 50;
private:
	bool isLoaded = 0;
	std::unique_ptr<Entity> checkType(sf::Color c, int x, int y);
	sf::Image level;
};
