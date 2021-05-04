#pragma once
#include <SFML/Graphics.hpp>
#include "MovableEntity.h"
#include "PlayerState.h"
#include "PlayerJumping.h"
#include "PlayerOnGround.h"
#include "PlayerFalling.h"

class Player {
public:
	Player();
	void handleInput(sf::Event& e);
	void update(float delta);
	void draw(sf::RenderWindow& window);
	void checkCollision(Interactive& e);
	sf::Vector2i getDir();
private:
	std::unique_ptr<PlayerState> playerState;
};