#pragma once
#include <SFML/Graphics.hpp>
#include "MovableEntity.h"
#include "PlayerState.h"
#include "PlayerJumping.h"
#include "PlayerOnGround.h"

class Player : public MovableEntity {
public:
	Player();
	void handleInput(sf::Event& e);
	void update(float delta, sf::Vector2f scroll) override;
	sf::Vector2i getDir();
private:
	std::unique_ptr<PlayerState> playerState;
};