#include "Dropdown.h"
using namespace sf;
void Dropdown::create(sf::Vector2f pos, sf::Vector2f size, const std::vector<std::string>& strs)
{
	buttons.resize(strs.size());
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i].create(Vector2f(pos.x, pos.y + size.y * i), size, strs[i]);
	}

	text.createRenderer();
}

std::string Dropdown::click(sf::Mouse& m, sf::RenderWindow &window)
{
	std::string ret;
	if (!m.isButtonPressed(Mouse::Left)) return std::string("");
	Vector2i mPos = m.getPosition(window);

	int max = isDropped ? buttons.size() : 1;

	for (int i = 0; i < buttons.size(); i++) {
		ret = buttons[i].onClick(m, window);
		if (ret != "\e") {
			isDropped = !isDropped;
			return ret;
		}
	}
}

void Dropdown::draw(sf::RenderWindow& window)
{
	int max = isDropped ? buttons.size() : 1;

	for (int i = 0; i < max; i++) 	buttons[i].draw(window, text);
}
