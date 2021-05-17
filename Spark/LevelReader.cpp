#include "LevelReader.h"
#include <iostream>
#include "Tile.h"
#include "Enemy.h"

using namespace sf;
void LevelReader::loadLevel(const std::string path, std::vector<std::unique_ptr<Entity>>& vec, const sf::RenderWindow& window, sf::Vector2i tile)
{
	if (!level.loadFromFile(path)) std::cout << "cant load lvl\n";;

	Vector2u worldSize = window.getSize();
	xTiles = worldSize.x / tileSize;
	yTiles = worldSize.y / tileSize;

	Vector2i presetOffset = { 3,5 };
	Vector2i startPos = tile - presetOffset;
	topLeft = startPos;
	topRight.y = startPos.y;
	leftSide = Vector2f( 0,0 );
	rightSide = Vector2f( (xTiles - 1) * tileSize,0 );

	for (int x = startPos.x; x < (startPos.x + xTiles); x++) {
		topRight.x = x;
		for (int y = startPos.y; y < (startPos.y + yTiles); y++) {
			Color c = level.getPixel(x, y);
			if (!c.a) continue;
			vec.push_back(checkType(c)); 
			vec.back()->createEntity(Vector2f(x * tileSize, y * tileSize), Vector2f(c.g * tileSize, c.b * tileSize));
			vec.back()->setPixelPos(Vector2i(x, y));
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
void LevelReader::loadNextLine(bool isRight, std::vector<std::unique_ptr<Entity>>& vec, sf::Vector2f scroll)
{
	if (isRight) {
		loadLine(Vector2i(topRight.x + 1, topRight.y), vec, rightSide - scroll);
		deleteLine(topLeft, vec);
		topLeft.x++; topRight.x++;
		std::cout << "one right\n";
	}
	else {
		loadLine(Vector2i(topLeft.x - 1, topLeft.y), vec, leftSide - scroll);
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

std::unique_ptr<Entity> LevelReader::checkType(sf::Color c)
{
	if(c.r == 0) return std::make_unique<Tile>();
	if (c.r == 1) return std::make_unique<Enemy>();
	std::cout << "couldnt read tile type\n";
	return nullptr;
}

void LevelReader::loadLine(sf::Vector2i firstPos, std::vector<std::unique_ptr<Entity>>& vec, sf::Vector2f startPos)
{
	if (firstPos.x < 0 || firstPos.x > level.getSize().x ||
		firstPos.y < 0 || firstPos.y > level.getSize().y) {
		std::cout << "Out of bounds\n";
		return;
	}

	for (int x = firstPos.x; x < firstPos.x + 1; x++) {
		for (int y = firstPos.y; y < (firstPos.y + yTiles); y++) {
			Color c = level.getPixel(x, y);
			if (!c.a) continue;
			vec.push_back(checkType(c));
			vec.back()->createEntity(Vector2f(startPos.x, startPos.y + y * tileSize), 
				Vector2f(c.g * tileSize,c.b * tileSize));
			vec.back()->setPixelPos(Vector2i(x,y));
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