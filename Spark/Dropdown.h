#pragma once
#include <SFML/Graphics.hpp>

class Dropdown {
public:
	void create(sf::Vector2f pos, sf::Vector2f size, const std::vector<std::string>& strs);
	std::string click(sf::Mouse &m, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
private:
	std::vector<sf::RectangleShape> shapes;
	std::vector<std::string> strings;
	bool isDropped = 0;
};