#pragma once
#include <SFML/Graphics.hpp>
#include "Dropdown.h"

class EditorSidebar {
public:
	EditorSidebar();
	bool handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape sideBarRect = sf::RectangleShape(sf::Vector2f(150, 480));
	Dropdown typeSelection;
};