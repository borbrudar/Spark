#include "Game.h"
#include <iostream>
using namespace sf;

Game::Game()
{
	gameState = std::make_unique<PlayState>();
}

void Game::handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::P) {
			if (id == stateID::play) {
				gameState = std::make_unique<Editor>(gameState.get()->getState());
				std::cout << "edit\n";
				id = stateID::edit;
			}
			else {
				gameState = std::make_unique<PlayState>(gameState.get()->getState());
				std::cout << "play\n";
				id = stateID::play;
			}
		}
	}

	gameState->handleInput(e,m,window);
}

void Game::draw(sf::RenderWindow& window)
{
	gameState->draw(window);
}

void Game::update(float delta)
{
	gameState->update(delta);
}
