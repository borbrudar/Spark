#pragma once
#include <SFML/Graphics.hpp>
#include "ISprite.h"
#include "AdvancedBox.h"
#include "Entity.h"


class PlayerState {
public:
	PlayerState();
	virtual ~PlayerState() {};
	virtual void handleInput(sf::Event& e);
	virtual std::unique_ptr<PlayerState> update(float delta, sf::Vector2f scroll) = 0;
	virtual void draw(sf::RenderWindow& window);

	void checkCollision(Entity& e);
	sf::Vector2i getDir();
protected:
	void updateBoxPosition();
	void horizontalCollision();
	void defaultResolveCollision();
	void basicBehaviour();
	void unscroll(sf::Vector2f scroll);

	AdvancedBox box;
	ISprite playerSprite;
	ID ID = ID::player;
	static int xdir, ydir;
	static sf::Vector2f pos, size, vel;

	std::shared_ptr<Entity> lastCol;
	static collisionInfo lastColInfo;

	const float constGrav = 90.f;
	float gravity = 90.f;

};
