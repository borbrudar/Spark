#include "LevelReader.h"
#include <iostream>
#include "Tile.h"
#include "Enemy.h"
#include "VisualTile.h"

using namespace sf;
void LevelReader::loadLevel(const std::string path, std::vector<std::unique_ptr<Entity>>& vec, const sf::RenderWindow& window, sf::Vector2i tile)
{
	if (!level.loadFromFile(path)) std::cout << "cant load lvl\n";

	//NOTE: the extra world buffering is not applied to the top of the map
	Vector2u worldSize = window.getSize();
	xTiles = worldSize.x / tileSize + extraWorld;
	yTiles = worldSize.y / tileSize + extraWorld;

	Vector2i presetOffset = { 3,5 };
	Vector2i startPos = tile - presetOffset;
	topLeft = Vector2i(startPos.x - extraWorld, startPos.y);
	topRight.y = startPos.y;

	for (int x = startPos.x - extraWorld; x < (startPos.x + xTiles + extraWorld); x++) {
		topRight.x = x;
		loadLine(Vector2i(x, startPos.y), vec);
	}

	isLoaded = 1;
}

void LevelReader::addBlock(sf::Color c, sf::Vector2i pos, sf::RenderWindow& window, Vector2i size)
{
	if (c.r == 0) level.setPixel( toTileCoords(pos.x,window), toTileCoords(pos.y,window),
		Color(c.r, toTileCoords(size.x,window), toTileCoords(size.y,window)));
	level.saveToFile("levels/level1.png");
}

void LevelReader::removeBlock(sf::Vector2i pos, sf::RenderWindow &window)
{
	level.setPixel(toTileCoords(pos.x,window), toTileCoords(pos.y,window), Color(0, 0, 0, 0));
	level.saveToFile("levels/level1.png");
}

void LevelReader::loadNextLine(sf::Vector2f &scroll, std::vector<std::unique_ptr<Entity>>& vec)
{
	if (scroll.x > tileSize) {
		scroll.x -= tileSize;
		loadLine(Vector2i(topRight.x + 1, topRight.y), vec);
		deleteLine(topLeft, vec);
		topLeft.x++; topRight.x++;
	}
	if (scroll.x < -tileSize) {
		scroll.x += tileSize;
		loadLine(Vector2i(topLeft.x - 1, topLeft.y), vec);
		deleteLine(topRight, vec);
		topLeft.x--; topRight.x--;
	}
}

int LevelReader::clampToTile(int pos, sf::RenderWindow& window)
{
	return static_cast<int>(window.mapPixelToCoords({ pos,pos }).x) / tileSize * tileSize;
}

int LevelReader::toTileCoords(int pos, sf::RenderWindow& window)
{
	return static_cast<int>(window.mapPixelToCoords({ pos,pos }).x) / tileSize;
}


Vector2i LevelReader::clampToTile(Vector2i pos, sf::RenderWindow& window)
{
	return Vector2i(clampToTile(pos.x,window), clampToTile(pos.y,window));
}

Vector2i LevelReader::toTileCoords(sf::Vector2i pos, sf::RenderWindow& window)
{
	return Vector2i(toTileCoords(pos.x,window), toTileCoords(pos.y,window));
}

bool LevelReader::getLoaded() 
{
	return isLoaded;
}

std::unique_ptr<Entity> LevelReader::checkType(sf::Color c)
{
	if(c.r == 0) return std::make_unique<Tile>();
	if (c.r == 1) return std::make_unique<Enemy>();
	if (c.r == 2) return std::make_unique<VisualTile>();
	std::cout << "couldnt read tile type\n";
	return nullptr;
}

void LevelReader::loadLine(sf::Vector2i firstPos, std::vector<std::unique_ptr<Entity>>& vec)
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
			vec.back()->createEntity(Vector2f(x * tileSize, y * tileSize), 
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