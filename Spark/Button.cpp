#include "Button.h"
#include "TextRenderer.h"
using namespace sf;


Button::Button()
{
}

void Button::create(sf::Vector2f pos, sf::Vector2f size, const std::string& str)
{
	buttonShape.setFillColor(Color::White);
	buttonShape.setOutlineThickness(1.f);
	buttonShape.setOutlineColor(Color(180, 180, 180));
	buttonShape.setSize(size);
	buttonShape.setPosition(pos);

	text = str;
}

void Button::draw(sf::RenderWindow& window, TextRenderer& rend)
{
	window.draw(buttonShape);
	rend.setPosition(buttonShape.getPosition());
	rend.setString(text);
	rend.draw(window);
}

std::string Button::onClick(sf::Mouse& m, sf::RenderWindow& window)
{
	Vector2i mPos = m.getPosition(window);
	if (!m.isButtonPressed(Mouse::Left) ||
		buttonShape.getGlobalBounds().contains(static_cast<Vector2f>(mPos))) return std::string("\e");

	return text;
}
