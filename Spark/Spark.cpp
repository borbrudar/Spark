#include "Spark.h"

Spark::Spark()
{
	window.create(sf::VideoMode(640, 480), "Spark");
}

void Spark::run()
{
	while (window.isOpen()) {
		update();
		draw();
	}
}

void Spark::draw()
{
	window.clear();
	window.display();
}

void Spark::update()
{
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) window.close();
	}
}
