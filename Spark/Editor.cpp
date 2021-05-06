#include "Editor.h"

using namespace sf;
Editor::Editor(SharedGameState& s)
{
	ss = std::move(s);
}

void Editor::handleInput(sf::Event& e, sf::Mouse& m)
{
}

void Editor::draw(sf::RenderWindow& window)
{
	GameState::draw(window);
}

void Editor::update(float delta)
{
}
