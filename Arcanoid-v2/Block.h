#pragma once
#include "Rectangle.h"
#include <SFML/Graphics.hpp>

using namespace sf;
enum BLOCK_TYPES {
	NOT_DESTROYED,
	ORDINARY,
	WITH_BONUS,
	INCREASE_SPEED,
	WITH_HEALTH
};

class Block : public Rectangle {
public:
	Block(int x, int y, float blockWidth, float blockHeight) : Rectangle(x, y, blockWidth, blockHeight) {

	}
	struct { // for block with health
		Color color[3] = { Color(255, 127, 80), Color(255, 99, 71), Color(255, 69, 0) };
		int lvl = 2;
	} withHealth;
	int type = ORDINARY; // type of block

	void SetColor(int type);
};

