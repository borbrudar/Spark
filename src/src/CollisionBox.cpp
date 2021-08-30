#include "CollisionBox.h"
using namespace sf;

void CollisionBox::create(sf::Vector2f pos, sf::Vector2f size)
{
	this->pos = pos; this->size = size;
	padding.x = size.x / 10; padding.y = size.y / 10;
	box.push_back(RectangleShape({ padding.x, size.y - padding.y * 2})); //left
	box.push_back(RectangleShape({ padding.x ,size.y - padding.y * 2})); //right

	box.push_back(RectangleShape({ size.x,padding.y })); //top
	box.push_back(RectangleShape({ size.x,padding.y })); //bottom

	for (int i = 0; i < box.size(); i++) box[i].setFillColor(Color(150 + i * 25,0,0,100 + i * 25));
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

collisionInfo CollisionBox::checkCollision(CollisionBox& other)
{
	collisionInfo inf;
	if (other.box[0].getGlobalBounds().intersects(box[1].getGlobalBounds())) {
		inf.right = 1;
	}
	if (other.box[1].getGlobalBounds().intersects(box[0].getGlobalBounds())) {
		inf.left = 1;
	}
	if (other.box[2].getGlobalBounds().intersects(box[3].getGlobalBounds())) {
		inf.bottom = 1;
	}
	if (other.box[3].getGlobalBounds().intersects(box[2].getGlobalBounds())) {
		inf.top = 1;
	}

	return inf;
}

sf::Vector2f CollisionBox::getPos()
{
	return pos;
}

void CollisionBox::updateBoxes()
{
	box[0].setPosition(pos.x, pos.y + padding.y); // left
	box[1].setPosition(pos.x + size.x - padding.x, pos.y + padding.y); //right
	box[2].setPosition(pos); //top
	box[3].setPosition(pos.x, pos.y + size.y - padding.y); //bottom
}

