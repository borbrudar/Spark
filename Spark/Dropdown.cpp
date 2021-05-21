#include "Dropdown.h"
using namespace sf;
void Dropdown::create(sf::Vector2f pos, sf::Vector2f size, const std::vector<std::string>& strs)
{
	shapes.resize(strs.size());
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i].setFillColor(Color::White);
		shapes[i].setSize(size);
		shapes[i].setPosition(pos.x, pos.y + size.y * i);
	}
	strings = strs;
	text.createRenderer();
}

std::string Dropdown::click(sf::Mouse& m, sf::RenderWindow &window)
{
	if (!m.isButtonPressed(Mouse::Left)) return std::string("");
	Vector2i mPos = m.getPosition(window);
	if (!isDropped) {
		if (shapes[0].getGlobalBounds().contains((Vector2f)mPos)) isDropped = 1;
		else isDropped = 0;
		return std::string("");
	}

	isDropped = 0;
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i].getGlobalBounds().contains((Vector2f)mPos)) 
			return strings[i];
	}
	return std::string("");
}

void Dropdown::draw(sf::RenderWindow& window)
{
	int max = isDropped ? strings.size() : 1;

	for (int i = 0; i < max; i++) {
		window.draw(shapes[i]);
		text.setPosition(shapes[i].getPosition());
		text.setString(strings[i]);
		text.draw(window);
	}
}
