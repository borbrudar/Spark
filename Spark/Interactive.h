#pragma once
#include "Entity.h"
#include "CollisionBox.h"
#include "ID.h"
#include "ISprite.h"

class Interactive : public Entity {
public:
	void inline defaultResolveCollision(Interactive& i) {
		box.checkCollision(i.box);
	}
	//updates collision box
	virtual void update(float delta, sf::Vector2f scroll);
protected:
	ID ID;
	CollisionBox box;
};
