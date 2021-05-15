#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
using namespace sf;

class Paddle : public GameObject, public sf::Drawable {
private:
	RectangleShape shape;
	float width = 180.f;
	const float height = 16.f;
	const float paddleVelocity = 13.f;
	Vector2f velocity{ paddleVelocity, 0.f };

	void draw(RenderTarget& target, RenderStates state) const;
public:
	Paddle(int x, int y);

	void update(float winWidth);
	void IncraseWidth();
	Vector2f getVelocity();
	void SetDefualtWidth();

	virtual Vector2f getPosition();
	virtual float left();
	virtual float right();
	virtual float top();
	virtual float bottom();
};

