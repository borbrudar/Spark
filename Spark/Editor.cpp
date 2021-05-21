#include "Editor.h"

using namespace sf;
Editor::Editor(SharedGameState& s)
{
	ss = std::move(s);

	std::vector<std::string> strings = { "---" , "Tile", "Enemy"};
	typeSelection.create(Vector2f(480, 20), Vector2f(70, 35), strings);

	editorView.setCenter(565, 240);
	editorView.setSize(150, 480);
	editorView.setViewport(FloatRect(0.8f, 0.f, 0.2f, 1.f));

	gameRect.setPosition(0, 0);
	gameRect.setSize(Vector2f(490, 480));
}

void Editor::handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	deltaPos = Vector2i((int)ss.totalScroll.x % tileSize, (int)ss.totalScroll.y % tileSize);
	//check if updating game editing or block selection
	if (gameRect.getGlobalBounds().contains((Vector2f)m.getPosition(window))) {
		addBlocks(e, m, window);
		removeBlocks(e, m, window);
	}
	else {
		typeSelection.click(m, window);
	}
}

void Editor::draw(sf::RenderWindow& window)
{
	GameState::draw(window);
	if (drawPreview) Tile::drawPreview((Vector2f)startPos, (Vector2f)endPos, window);

	window.setView(editorView);
	typeSelection.draw(window);

	window.setView(window.getDefaultView());
}

void Editor::update(float delta)
{
	for(int i = 0; i < ss.entities.size();i++)
	ss.entities[i]->update(delta, sf::Vector2f(0, 0));
}

void Editor::addBlocks(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	if (e.mouseButton.button == Mouse::Left) {
		drawPreview = 1;
		if (e.type == Event::MouseButtonPressed) {
			Vector2i mPos = m.getPosition(window);
			startPos = LevelReader::clampToTile(mPos) - deltaPos;
		}
		else if (e.type == Event::MouseButtonReleased) {
			Vector2i size = endPos - startPos;
			ss.entities.push_back(std::make_unique<Tile>());
			ss.entities.back()->createEntity((Vector2f)startPos, (Vector2f)size);
			ss.level.addBlock(Color(0, size.x, size.y), startPos,(Vector2i)ss.totalScroll, size);
			drawPreview = 0;
		}
	}
	auto mPos = m.getPosition(window);
	endPos = LevelReader::clampToTile(mPos, { 1,1 }) - deltaPos;
}

void Editor::removeBlocks(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	if (m.isButtonPressed(Mouse::Right)) {
		Vector2i mPos = m.getPosition(window);
		Vector2i tilePos;
		for (int i = 0; i < ss.entities.size(); i++) {
			if (ss.entities[i]->box->contains(mPos)) {
				tilePos = (Vector2i)ss.entities[i]->box->getPos();
				ss.entities.erase(ss.entities.begin() + i);
				break;
			}
		}
		ss.level.removeBlock(tilePos, (Vector2i)ss.totalScroll);
	}
}
