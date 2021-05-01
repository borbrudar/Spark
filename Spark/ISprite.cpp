#include "ISprite.h"

ISprite::ISprite(sf::Vector2f pos, sf::Vector2f size, sf::Color c)
{
	setSprite(pos, size, c);
}

void ISprite::draw(sf::RenderWindow& window)
{
	window.draw(s);
}

void ISprite::setSprite(sf::Vector2f pos, sf::Vector2f size, sf::Color c)
{
	s.setFillColor(sf::Color(c.r,c.g,c.b,c.a));
	s.setPosition(pos);
	s.setSize(size);
}
