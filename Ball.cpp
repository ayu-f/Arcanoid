#include "Ball.h"

Ball::Ball(int x, int y) : Circle(x, y){
}

void Ball::SetSpeedDefualt() {
    ballVelocity = 6.f;
}


void Ball::SpeedUp() {
    ballVelocity += 1.f;
}

void Ball::moveDown() {
    this->velocity.y = ballVelocity;
};

void Ball::moveUp() {
    this->velocity.y = -ballVelocity;
};

void Ball::moveRight() {
    this->velocity.x = ballVelocity;
};

void Ball::moveLeft() {
    this->velocity.x = -ballVelocity;
};

void Ball::SpeedDown() {
    ballVelocity -= 1.5f;
    velocity = { ballVelocity, ballVelocity };
}

void Ball::FollowPaddle(Vector2f vec) {
    shape.move(this->velocity);
}

void Ball::setPosition(Vector2f position) {
    shape.setPosition({ position.x, position.y - shape.getRadius() + 5.f });
}

void Ball::ReflectX() {
    velocity.x = -velocity.x;
}
