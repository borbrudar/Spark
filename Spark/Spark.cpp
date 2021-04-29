#include "Spark.h"

Spark::Spark()
{
	window.create(sf::VideoMode(640, 480), "Spark");
	state.push_back(std::make_unique<PlayState>());
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
	state[0]->handleInput(e);
}

void Spark::draw()
{
	window.clear();
	state[0]->draw(window);
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
		state[0]->update(deltaTime);
		frameTime -= deltaTime;
	}

}
