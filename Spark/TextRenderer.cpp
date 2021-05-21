#include "TextRenderer.h"
using namespace sf;
Font TextRenderer::font = Font();

TextRenderer::TextRenderer()
{
	font.loadFromFile("font/arial.ttf");
}

sf::Text& TextRenderer::getText()
{
	return text;
}

void TextRenderer::setString(std::string txt)
{
	text.setString(txt);
}

void TextRenderer::createRenderer(sf::Vector2f pos, unsigned int chSize)
{
	text.setCharacterSize(chSize);
	text.setFillColor(Color::Black);
	text.setFont(font);
	text.setPosition(pos);
}

void TextRenderer::setPosition(sf::Vector2f pos)
{
	text.setPosition(pos);
}

void TextRenderer::draw(sf::RenderWindow& window)
{
	window.draw(text);
}
