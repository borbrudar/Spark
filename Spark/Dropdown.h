#pragma once
#include <SFML/Graphics.hpp>
#include "TextRenderer.h"
#include "Button.h"

class Dropdown {
public:
	void create(sf::Vector2f pos, sf::Vector2f size, const std::vector<std::string>& strs);
	std::string click(sf::Mouse &m, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
private:
	TextRenderer text;
	std::vector<Button> buttons;
	bool isDropped = 0;
};