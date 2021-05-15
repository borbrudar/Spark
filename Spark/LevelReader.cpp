#include "LevelReader.h"
#include <iostream>
#include "Tile.h"
#include "Enemy.h"

using namespace sf;
void LevelReader::loadLevel(std::string path, std::vector<std::unique_ptr<Entity>>& vec)
{
	if (!level.loadFromFile(path)) std::cout << "cant load lvl\n";;

	int sizeX = level.getSize().x, sizeY = level.getSize().y;
	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			if (!level.getPixel(x, y).a) continue;
			vec.push_back(checkType(level.getPixel(x,y),x * tileSize, y * tileSize));
		}
	}
}
void LevelReader::addBlock(sf::Color c, sf::Vector2i pos, sf::Vector2i scroll, Vector2i size)
{
	if (c.r == 0) level.setPixel( toTileCoords(pos.x + scroll.x), toTileCoords(pos.y + scroll.y),
		Color(c.r, toTileCoords(size.x), toTileCoords(size.y)));
	level.saveToFile("levels/level1.png");
}

void LevelReader::removeBlock(sf::Vector2i pos, sf::Vector2i scroll)
{
	level.setPixel(toTileCoords(pos.x + scroll.x), toTileCoords(pos.y + scroll.y), Color(0, 0, 0, 0));
	level.saveToFile("levels/level1.png");
}

sf::Vector2i LevelReader::clampToTile(sf::Vector2i pos, sf::Vector2i offset)
{
	return sf::Vector2i(clampToTile(pos.x,offset.x), clampToTile(pos.y,offset.y));
}

sf::Vector2i LevelReader::toTileCoords(sf::Vector2i pos, sf::Vector2i offset)
{
	return sf::Vector2i(toTileCoords(pos.x,offset.x),toTileCoords(pos.y,offset.y));
}

int LevelReader::clampToTile(int pos, int offset)
{
	return pos / tileSize * tileSize + (offset * tileSize);
}

int LevelReader::toTileCoords(int pos, int offset)
{
	return pos / tileSize + offset;
}


std::unique_ptr<Entity> LevelReader::checkType(sf::Color c, int x, int y)
{
	if(c.r == 0) return std::make_unique<Tile>(Vector2f(x,y), Vector2f(tileSize * c.g,tileSize * c.b));
	if (c.r == 1) return std::make_unique<Enemy>(Vector2f(x,y));
	std::cout << "couldnt read tile type\n";
	return nullptr;
}

