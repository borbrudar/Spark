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
	void updateBoxPosition();
	void horizontalCollision();
	void defaultResolveCollision();

	CollisionBox box;
	ISprite playerSprite;
	ID ID = ID::player;
	static int xdir, ydir;
	static sf::Vector2f pos, size, vel;

	std::unique_ptr<Interactive> lastCol;
	static collisionType lastColType;

	const float constGrav = 90.f;
	float gravity = 90.f;

};
