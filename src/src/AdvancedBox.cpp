#include "AdvancedBox.h"
using namespace sf;

void AdvancedBox::create(sf::Vector2f pos, sf::Vector2f size)
{
	this->pos = pos; this->size = size;
	padding.x = size.x / 10; padding.y = size.y / 10;
	box.push_back(RectangleShape({ padding.x, size.y - padding.y * 2})); //left
	box.push_back(RectangleShape({ padding.x ,size.y - padding.y * 2})); //right

	box.push_back(RectangleShape({ size.x - padding.x * 2,padding.y })); //top
	box.push_back(RectangleShape({ size.x - padding.x * 2,padding.y })); //bottom

	for (int i = 0; i < box.size(); i++) box[i].setFillColor(Color(150 + i * 25,0,0,100 + i * 25));
}

collisionInfo AdvancedBox::checkCollision(CollisionBox& other)
{
	collisionInfo inf;
	if (box[0].getGlobalBounds().intersects(other.getBox().back().getGlobalBounds())) inf.left = 1;
	if (box[1].getGlobalBounds().intersects(other.getBox().back().getGlobalBounds())) inf.right = 1;
	if (box[2].getGlobalBounds().intersects(other.getBox().back().getGlobalBounds())) inf.top = 1;
	if (box[3].getGlobalBounds().intersects(other.getBox().back().getGlobalBounds())) inf.bottom = 1;
	return inf;
}

#include <iostream>
collisionInfo AdvancedBox::checkCollision(AdvancedBox& other)
{
	// fixed advanced collisions
	collisionInfo inf;
	std::cout << "cant do advanced collisions yet\n";
	/*if (other.box[0].getGlobalBounds().intersects(box[1].getGlobalBounds())) {
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
	}*/

	return inf;
}

void AdvancedBox::updateBoxes()
{
	box[0].setPosition(pos.x, pos.y + padding.y); // left
	box[1].setPosition(pos.x + size.x - padding.x, pos.y + padding.y); //right
	box[2].setPosition(pos.x + padding.x,pos.y); //top
	box[3].setPosition(pos.x + padding.x, pos.y + size.y - padding.y); //bottom
}

