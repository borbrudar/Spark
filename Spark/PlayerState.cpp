#include "PlayerState.h"
using namespace sf;

sf::Vector2f PlayerState::pos = sf::Vector2f(100, 120), PlayerState::size = sf::Vector2f(50, 50),
PlayerState::vel = sf::Vector2f(0, 0);

collisionInfo PlayerState::lastColInfo = collisionInfo();

int PlayerState::xdir = 0, PlayerState::ydir = 0;

PlayerState::PlayerState()
{
	box.create(pos, size);
	playerSprite.setSprite(pos, size, Color::Red);
}


void PlayerState::handleInput(sf::Event& e)
{
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Left) xdir = -1;
		if (e.key.code == Keyboard::Right) xdir = 1;
		if (e.key.code == Keyboard::Up) ydir = 1;
	}
	if (e.type == Event::KeyReleased) {
		if (e.key.code == Keyboard::Left) xdir = 0;
		if (e.key.code == Keyboard::Right) xdir = 0;
		if (e.key.code == Keyboard::Up) ydir = 0;
	}
}

void PlayerState::draw(sf::RenderWindow& window)
{
	playerSprite.updatePos(pos);
	//playerSprite.draw(window);
	box.draw(window);
}


void PlayerState::checkCollision(Entity& e)
{
	collisionInfo temp = box.checkCollision(*e.box);
	if (!temp.isNoCollision()) {
		lastColInfo += temp;
		lastCol = std::make_shared<Entity>(e);
	}
}

sf::Vector2i PlayerState::getDir()
{
	return sf::Vector2i(xdir,0);
}

void PlayerState::updateBoxPosition()
{
	box.setPosition(pos);
}

void PlayerState::horizontalCollision()
{
	if ((xdir == 1 && lastColInfo.right) ||
		(xdir == -1 && lastColInfo.left))
		xdir = 0;	
}

void PlayerState::defaultResolveCollision()
{
	if (!lastColInfo.isNoCollision()) box.defaultResolveCollision();
}

void PlayerState::basicBehaviour()
{
	updateBoxPosition();
	horizontalCollision();
	defaultResolveCollision();
}

void PlayerState::unscroll(sf::Vector2f scroll)
{
	pos += scroll;
}
