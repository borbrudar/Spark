#pragma once
#include "Entity.h"
#include "CollisionBox.h"
#include "CollisionInfo.h"
#include "ISprite.h"

class Interactive : public Entity {
public:
	void inline defaultResolveCollision(Interactive& i) {
		box.checkCollision(i.box);
	}
	virtual void update(float delta, sf::Vector2f scroll);
protected:
	ID ID;
	CollisionBox box;
};
