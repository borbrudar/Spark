#include "LevelReader.h"
#include <iostream>
#include "Tile.h"
#include "Enemy.h"

using namespace sf;
void LevelReader::loadLevel(const std::string path, std::vector<std::unique_ptr<Entity>>& vec, const sf::RenderWindow& window, sf::Vector2i tile)
{
	if (!level.loadFromFile(path)) std::cout << "cant load lvl\n";;

	Vector2u worldSize = window.getSize();
	xTiles = worldSize.x / tileSize + 1;
	yTiles = worldSize.y / tileSize + 1;

	Vector2i presetOffset = { 3,5 };
	Vector2i startPos = tile - presetOffset;
	topLeft = startPos;
	topRight.y = startPos.y;

	for (int x = startPos.x; x < (startPos.x + xTiles); x++) {
		topRight.x = x;
		for (int y = startPos.y; y < (startPos.y + yTiles); y++) {
			if (!level.getPixel(x, y).a) continue;
			vec.push_back(checkType(level.getPixel(x, y), Vector2i(x,y)));
			vec.back()->setPixelPos(Vector2i(startPos.x + x, startPos.y + y));
		}
	}

	isLoaded = 1;
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

#include <iostream>
void LevelReader::loadNextLine(bool isRight, std::vector<std::unique_ptr<Entity>>& vec)
{
	if (isRight) {
		loadLine(Vector2i(topRight.x + 1, topRight.y), vec);
		deleteLine(topLeft, vec);
		topLeft.x++; topRight.x++;
		std::cout << "one right\n";
	}
	else {
		loadLine(Vector2i(topLeft.x - 1, topLeft.y), vec);
		deleteLine(topRight, vec);
		topLeft.x--; topRight.x--;
		std::cout << "one left\n";
	}
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

bool LevelReader::getLoaded() 
{
	return isLoaded;
}


std::unique_ptr<Entity> LevelReader::checkType(sf::Color c, sf::Vector2i tilePos, sf::Vector2i tileOffset)
{
	Vector2f pos = Vector2f((tilePos.x - tileOffset.x) * tileSize,(tilePos.y - tileOffset.y) * tileSize);
	if(c.r == 0) return std::make_unique<Tile>(pos, Vector2f(tileSize * c.g, tileSize * c.b));
	if (c.r == 1) return std::make_unique<Enemy>(pos);
	std::cout << "couldnt read tile type\n";
	return nullptr;
}

void LevelReader::loadLine(sf::Vector2i firstPos, std::vector<std::unique_ptr<Entity>>& vec)
{
	for (int x = firstPos.x; x < firstPos.x + 1; x++) {
		for (int y = firstPos.y; y < (firstPos.y + yTiles); y++) {
			if (!level.getPixel(x, y).a) continue;
			vec.push_back(checkType(level.getPixel(x, y),Vector2i(x,y), firstPos));
			vec.back()->setPixelPos(Vector2i(firstPos.x + x,firstPos.y + y));
		}
	}
}

void LevelReader::deleteLine(sf::Vector2i firstPos, std::vector<std::unique_ptr<Entity>>& vec)
{
	for (int i = 0; i < vec.size(); i++) {
		Vector2i pixelPos = vec[i]->getPixelPos();
		if (pixelPos.x != firstPos.x) continue;
		if (!(pixelPos.y >= firstPos.y && pixelPos.y < (firstPos.y + yTiles))) continue;
		vec.erase(vec.begin() + i);
		i--;
	}
}