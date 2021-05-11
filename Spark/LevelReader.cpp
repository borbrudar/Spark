#include "LevelReader.h"
#include <iostream>
#include "Tile.h"
using namespace sf;
void LevelReader::loadLevel(std::string path, std::vector<std::unique_ptr<Entity>>& vec, int tileSize)
{
	this->tileSize = tileSize;
	if (!level.loadFromFile(path)) std::cout << "cant load lvl\n";;

	int sizeX = level.getSize().x, sizeY = level.getSize().y;
	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			if (!level.getPixel(x, y).a) continue;
			vec.push_back(checkType(level.getPixel(x,y),x * tileSize, y * tileSize));
		}
	}
}

std::unique_ptr<Entity> LevelReader::checkType(sf::Color c, int x, int y)
{
	if(c == Color(0,0,0)) return std::make_unique<Tile>(Vector2f(x,y), Vector2f(tileSize,tileSize));
	std::cout << "couldnt read tile type\n";
	return nullptr;
}

