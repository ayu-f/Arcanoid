#include "Bonus.h"

void Bonus::SetColor() {
	switch (type)
	{
	case CHANGE_WIDTH_PADDLE:
		shape.setFillColor(Color::Red); // red
		break;
	case DECREASE_SPEEDBALL:
		shape.setFillColor(Color(0, 255, 255)); // cyan
		break;
	case BALL_STICKING:
		shape.setFillColor(Color::Yellow);
		break;
	case CHANGE_TRAJECTORY:
		shape.setFillColor(Color::Magenta);
		break;
	case SET_FLOOR:
		shape.setFillColor(Color::Green);
		break;
	case SECOND_BALL:
		shape.setFillColor(Color::White);
		break;
	default:
		break;
	}
}

float Bonus::left() {
	return this->shape.getPosition().x - shape.getRadius();
}

float Bonus::right() {
	return this->shape.getPosition().x + shape.getRadius();
}

float Bonus::top() {
	return this->shape.getPosition().y - shape.getRadius();
}

float Bonus::bottom() {
	return this->shape.getPosition().y + shape.getRadius();
}

Vector2f Bonus::getPosition() {
	return shape.getPosition();
}
