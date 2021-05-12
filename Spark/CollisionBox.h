#pragma once
#include <SFML/Graphics.hpp>

struct collisionInfo {
	bool inline isNoCollision() { return !(left || right || top || bottom); };
	void inline reset() { left = 0; right = 0; top = 0; bottom = 0; };
	collisionInfo operator+=(collisionInfo& rhs) {
		left = left || rhs.left;
		right = right || rhs.right;
		top = top || rhs.top;
		bottom = bottom || rhs.bottom;
		return *this;
	}
	bool left = 0, right = 0, top = 0, bottom = 0;
};

class CollisionBox {
public:
	virtual void create(sf::Vector2f pos, sf::Vector2f size);
	virtual collisionInfo checkCollision(CollisionBox& other) = 0;


	void setPosition(sf::Vector2f newPos);
	void draw(sf::RenderWindow& window);
	void defaultResolveCollision();
	void move(sf::Vector2f by);
	void move(float x, float y) { move(sf::Vector2f(x, y)); };
	bool contains(sf::Vector2i pos);
	sf::Vector2f getPos();
private:
	virtual void updateBoxes();
	std::vector<sf::RectangleShape> box;
	sf::Vector2f pos, size, prevPos;
	sf::Vector2f padding;
};