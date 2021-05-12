#include "CollisionBox.h"
using namespace sf;

void CollisionBox::create(sf::Vector2f pos, sf::Vector2f size)
{
	box.push_back(RectangleShape(size));
	box.back().setPosition(pos);
	box.back().setFillColor(Color::Red);
}

void CollisionBox::setPosition(sf::Vector2f newPos)
{
	prevPos = pos;
	pos = newPos;
	updateBoxes();
}

void CollisionBox::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < box.size(); i++) window.draw(box[i]);
}

void CollisionBox::defaultResolveCollision()
{
	pos = prevPos;
}

void CollisionBox::move(sf::Vector2f by)
{
	prevPos = pos;
	pos += by;
	updateBoxes();
}

bool CollisionBox::contains(sf::Vector2i pos)
{
	return IntRect(static_cast<Vector2i>(this->pos), static_cast<Vector2i>(size)).contains(pos);
}

sf::Vector2f CollisionBox::getPos()
{
	return pos;
}

std::vector<sf::RectangleShape>& CollisionBox::getBox()
{
	return box;
}

void CollisionBox::updateBoxes()
{
	box[0].setPosition(pos);
}
