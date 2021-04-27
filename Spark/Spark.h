#pragma once
#include <SFML/Graphics.hpp>

class Spark {
public:
	Spark();

	void run();
	void draw();
	void update();

	sf::RenderWindow window;
	sf::Event e;
};