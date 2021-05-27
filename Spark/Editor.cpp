#include "Editor.h"

using namespace sf;
Editor::Editor(SharedGameState& s)
{
	ss = std::move(s);
}

void Editor::handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	Vector2i mPos = m.getPosition(window);
	if (!sidebar.handleInput(e,m,window)) {
		deltaPos = Vector2i((int)ss.totalScroll.x % tileSize, (int)ss.totalScroll.y % tileSize);
		addBlocks(e, m, window);
		removeBlocks(e, m, window);
	}else 	

	scrollInput(e);
	ss.level.loadNextLine(ss.loadScroll, ss.entities);
}

void Editor::draw(sf::RenderWindow& window)
{
	GameState::draw(window);
	if (drawPreview) Tile::drawPreview((Vector2f)startPos, (Vector2f)endPos, window);
	

	window.setView(ss.editorView);
	sidebar.draw(window);
	window.setView(ss.gameView);
}

void Editor::update(float delta)
{
	updateScroll(delta);
	ss.gameView.move(scroll);
	for(int i = 0; i < ss.entities.size();i++)
	ss.entities[i]->update(delta);
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
