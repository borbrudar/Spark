#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerState.h"
#include "PlayerJumping.h"
#include "PlayerOnGround.h"
#include "PlayerFalling.h"

class Player {
public:
	Player();
	void handleInput(sf::Event& e);
	void update(float delta, sf::Vector2f scroll);
	void draw(sf::RenderWindow& window);
	void checkCollision(Entity& e);
	sf::Vector2i getDir();
private:
	std::unique_ptr<PlayerState> playerState;
};