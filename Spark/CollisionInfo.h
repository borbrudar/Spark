#pragma once


enum class ID {
	player,
	enemy,
	tile
};

enum class collisionType {
	none,
	left,
	right,
	top,
	bottom
};


class CollisionInfo {
public:
	ID senderID;
	collisionType type;
};