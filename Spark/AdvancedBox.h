#pragma once
#include "CollisionBox.h"
#include <vector>
#include "ID.h"

class AdvancedBox : public CollisionBox{
public:
	void create(sf::Vector2f pos, sf::Vector2f size) override;
	collisionInfo checkCollision(CollisionBox& other) override;
private:
	void updateBoxes() override;
};