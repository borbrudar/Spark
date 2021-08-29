#pragma once
#include <SFML/Graphics.hpp>

class ISprite {
public:
	ISprite() = default;
	ISprite(sf::Vector2f pos, sf::Vector2f size, sf::Color c);
	void draw(sf::RenderWindow& window);
	void updatePos(sf::Vector2f pos);
	void setSprite(sf::Vector2f pos, sf::Vector2f size, sf::Color c);
private:
	sf::RectangleShape s;
};
