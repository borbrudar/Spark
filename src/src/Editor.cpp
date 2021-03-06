#include "Editor.h"

using namespace sf;
Editor::Editor(SharedGameState& s)
{
	ss = std::move(s);
}

void Editor::handleInput(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	scrollInput(e);

	Vector2i mPos = m.getPosition(window);
	if (!sidebar.handleInput(e,m,window)) {
		deltaPos = Vector2i((int)ss.totalScroll.x % tileSize, (int)ss.totalScroll.y % tileSize);
		addBlocks(e, m, window);
		removeBlocks(e, m, window);
	}	
	
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
	ss.level.loadNextLine(ss.loadScroll, ss.entities);
	updateScroll(delta);
	ss.gameView.move(scroll);
	for(int i = 0; i < ss.entities.size();i++)
	ss.entities[i]->update(delta);
}

void Editor::addBlocks(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{	
		if (m.isButtonPressed(Mouse::Left)) {
			drawPreview = 1;
			Vector2i mPos = m.getPosition(window);
			startPos = LevelReader::clampToTile(mPos,window);
			endPos = LevelReader::clampToTile(mPos, window, { 1,1 });

			//add if its empty
			for (int i = 0; i < ss.entities.size(); i++)
				if (ss.entities[i]->getPixelPos() == (Vector2i)LevelReader::toTileCoords(startPos, window)) return;

			ss.entities.push_back(std::make_unique<Tile>());
			ss.entities.back()->createEntity((Vector2f)startPos,
				Vector2f(LevelReader::tileSize, LevelReader::tileSize));
			ss.entities.back()->setPixelPos((Vector2i)LevelReader::toTileCoords(startPos, window));
			ss.level.addBlock(Color(0, 50, 50), startPos, window, { 0,0 });
		}
		else if (e.type == Event::MouseButtonReleased) {
			drawPreview = 0;
		}
	
}

void Editor::removeBlocks(sf::Event& e, sf::Mouse& m, sf::RenderWindow& window)
{
	if (m.isButtonPressed(Mouse::Right)) {
		Vector2i mPos = m.getPosition(window);
		mPos = (Vector2i)window.mapPixelToCoords(mPos);
		Vector2i pos;
		for (int i = 0; i < ss.entities.size(); i++) {
			if (ss.entities[i]->box->contains(mPos)) {
				pos = (Vector2i)ss.entities[i]->box->getPos();
				ss.entities.erase(ss.entities.begin() + i);
				break;
			}
		}
		ss.level.removeBlock(pos,window);
	}
}
