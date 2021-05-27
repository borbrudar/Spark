#pragma once
#include <SFML/Graphics.hpp>

class TextRenderer;
class Button {
public:
	Button();
	void create(sf::Vector2f pos, sf::Vector2f size, const std::string &str);
	void draw(sf::RenderWindow& window, TextRenderer &rend);
	std::string onClick(sf::Mouse& m, sf::RenderWindow &window);
private:
	sf::RectangleShape buttonShape;
	std::string text;
};
