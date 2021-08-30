#pragma once
#include <SFML/Graphics.hpp>


class TextRenderer {
public:
	TextRenderer();
	sf::Text& getText();
	void setString(std::string txt);
	void createRenderer(sf::Vector2f pos = { 0, 0}, unsigned int chSize = 14);
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
private:
	static sf::Font font;
	sf::Text text;
};

