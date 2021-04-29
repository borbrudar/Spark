#include "PlayerOnGround.h"
#include "PlayerJumping.h"

using namespace sf;
std::unique_ptr<PlayerState> PlayerOnGround::handleInput(sf::Event& e)
{
	PlayerState::handleInput(e);
	if (e.type == Event::KeyPressed) {
		if (e.key.code == Keyboard::Up) return std::make_unique<PlayerJumping>();
	}

	return nullptr;
}

void PlayerOnGround::draw(sf::RenderWindow& window)
{
}
