#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;


class Rectangle : public GameObject, public sf::Drawable {
public:
	virtual void draw(sf::RenderTarget& targer, sf::RenderStates states) const;

	RectangleShape shape;
	bool destroyed = false;
public:
	Rectangle(int x, int y, float blockWidth, float blockHeight);

	virtual  Vector2f getPosition();
	virtual float left();
	virtual float right();
	virtual float top();
	virtual float bottom();

	bool isDestroyed();
	void destroy();
	Vector2f getSize();

};

