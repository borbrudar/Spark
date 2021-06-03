#include "EditorSidebar.h"
using namespace sf;

EditorSidebar::EditorSidebar() {

	std::vector<std::string> strings = { "---", "Tile", "Enemy", "Visual" };
	typeSelection.create(Vector2f(550, 20), Vector2f(70, 35), strings);

	sideBarRect.setFillColor(sf::Color(255, 255, 255, 160));
	sideBarRect.setPosition(Vector2f(490, 0));
}

bool EditorSidebar::handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	Vector2i mPos = m.getPosition(window);
	if (!sideBarRect.getGlobalBounds().contains(static_cast<Vector2f>(mPos))) return false;

	typeSelection.click(m, window);
		
	return true;
}

void EditorSidebar::draw(sf::RenderWindow& window)
{
	window.draw(sideBarRect);
	typeSelection.draw(window);
}
