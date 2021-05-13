#pragma once
#include "Circle.h"
#include "Rectangle.h"

enum BONUS_TYPES {
	CHANGE_WIDTH_PADDLE,
	DECREASE_SPEEDBALL,
	BALL_STICKING,
	SET_FLOOR,
	CHANGE_TRAJECTORY,
	SECOND_BALL
};

class Bonus : public Circle {
private:
	void SetColor();
public:
	bool isActive = false;
	struct {
		Rectangle rect{ 1024 / 2, 760, 1024, 6 };
		bool active = false;
	}floor;
	int type = 5; // delete 
	Bonus(int x, int y) : Circle(x, y) {
		ballRadius = 5.f;
		ballVelocity = 14.f;
		shape.setRadius(this->ballRadius);
		velocity = { 0, ballVelocity };
	}

	void SetType(int type) {
		this->type = type;
		SetColor();
	}

	void SetPosition(Vector2f position) {
		shape.setPosition(position);
	}

	virtual  Vector2f getPosition();
	virtual float left();
	virtual float right();
	virtual float top();
	virtual float bottom();
};