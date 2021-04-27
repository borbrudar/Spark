#include "Spark.h"

Spark::Spark()
{
	window.create(sf::VideoMode(640, 480), "Spark");
	gameState.push_back(std::make_unique<Game>());
}

void Spark::run()
{
	while (window.isOpen()) {
		handleInput();
		update();
		draw();
	}
}

void Spark::handleInput()
{
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) window.close();
	}
	gameState[0]->handleInput(e);
}

void Spark::draw()
{
	window.clear();
	gameState[0]->draw(window);
	window.display();
}

void Spark::update()
{
	//timestep
	double newTime = clock.getElapsedTime().asSeconds();
	double frameTime = newTime - currentTime;
	currentTime = newTime;

	while (frameTime > 0.0)
	{
		float deltaTime = std::min(frameTime, dt);
		gameState[0]->update(deltaTime);
		frameTime -= deltaTime;
	}

}
