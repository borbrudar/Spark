#include "Editor.h"

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
