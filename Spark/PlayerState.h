#pragma once
#include <SFML/Graphics.hpp>
#include "ISprite.h"
#include "CollisionBox.h"
#include "Interactive.h"

class PlayerState {
public:
	PlayerState();
	virtual ~PlayerState() {};
	virtual void handleInput(sf::Event& e);
	virtual std::unique_ptr<PlayerState> update(float delta) = 0;
	virtual void draw(sf::RenderWindow& window);

	void checkCollision(Interactive& e);
	sf::Vector2i getDir();
protected:
	void applyGravity(float delta);

	CollisionBox box;
	ISprite playerSprite;
	ID ID = ID::player;
	int xdir = 0, ydir = 0;
	sf::Vector2f pos;
	std::unique_ptr<Interactive> lastCol;
	collisionType lastColType = collisionType::none;

	const float constGrav = 50.f;
	float gravity = 50.f;
};