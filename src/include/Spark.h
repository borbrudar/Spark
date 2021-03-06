#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include <vector>


class Spark {
public:
	Spark();
	void run();
private:
	void handleInput();
	void draw();
	void update();
	
	sf::Event e;
	sf::RenderWindow window;
	sf::Mouse m;

	std::vector<std::unique_ptr<State>> state;
	//timestep
	sf::Clock clock;
	double dt = 1 / 60.f, currentTime = clock.getElapsedTime().asSeconds();
};