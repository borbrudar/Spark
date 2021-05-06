#include "Editor.h"

using namespace sf;
Editor::Editor(SharedGameState& s)
{
	ss = std::move(s);
}

void Editor::handleInput(sf::Event& e)
{
}

void Editor::draw(sf::RenderWindow& window)
{
	GameState::draw(window);
	


}

void Editor::update(float delta)
{
}

void Editor::setMouse(sf::RenderWindow& window)
{
	window.setMouseCursorVisible(1);
}
