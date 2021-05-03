#include "CollisionBox.h"
using namespace sf;

void CollisionBox::create(sf::Vector2f pos, sf::Vector2f size)
{
	this->pos = pos; this->size = size;
	box.push_back(RectangleShape({ 3, size.y }));
	box.back().setPosition(pos);
	box.push_back(RectangleShape({ 3,size.y }));
	box.back().setPosition(pos.x + size.y,pos.y);

	box.push_back(RectangleShape({ size.x,4 }));
	box.back().setPosition(pos);
	box.push_back(RectangleShape({ size.x,5 }));
	box.back().setPosition(pos.x,pos.y + size.y);

	for (int i = 0; i < box.size(); i++) box[i].setFillColor(Color::Red);
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


collisionType CollisionBox::checkCollision(CollisionBox& other)
{
	if (other.box[0].getGlobalBounds().intersects(box[1].getGlobalBounds())) {
		return collisionType::right;
	}
	if (other.box[1].getGlobalBounds().intersects(box[0].getGlobalBounds())) {
		return collisionType::left;
	}
	if (other.box[2].getGlobalBounds().intersects(box[3].getGlobalBounds())) {
		return collisionType::top;
	}
	if (other.box[3].getGlobalBounds().intersects(box[2].getGlobalBounds())) { 
		return collisionType::bottom; }

	return collisionType::none;
}

sf::Vector2f CollisionBox::getPos()
{
	return pos;
}

void CollisionBox::updateBoxes()
{
	box[0].setPosition(pos);
	box[1].setPosition(pos.x + size.x, pos.y);
	box[2].setPosition(pos);
	box[3].setPosition(pos.x, pos.y + size.y);
}
