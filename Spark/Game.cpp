#include "Game.h"
#include <typeinfo>
#include <iostream>
using namespace sf;
Game::Game()
{
	gameState = std::make_unique<PlayState>();
}

void Game::handleInput(sf::Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::P) {
			if (typeid(*gameState.get()).name() == typeid(PlayState).name()) {
				gameState = std::make_unique<Editor>(gameState.get()->getState());
				std::cout << "edit\n";
			}
			else {
				gameState = std::make_unique<PlayState>(gameState.get()->getState());
				std::cout << "play\n";
			}
		}
	}

	gameState->handleInput(e);
}

void Game::draw(sf::RenderWindow& window)
{
	gameState->draw(window);
}

void Game::update(float delta)
{
	gameState->update(delta);
}
