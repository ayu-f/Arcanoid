#include "Circle.h"

Circle::Circle(int x, int y) {
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
    shape.setRadius(this->ballRadius);
    shape.setFillColor(color);
    shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Circle::draw(RenderTarget& target, RenderStates state) const {
    target.draw(this->shape, state);
}

bool Circle::update(unsigned int winWidth, unsigned int winHeight) {
    shape.move(this->velocity);

    if (this->left() < 0) {
        velocity.x = ballVelocity;
    }
    else if (this->right() > winWidth) {
        velocity.x = -ballVelocity;
    }
    else if (this->top() < 0) {
        velocity.y = ballVelocity;
    }
    else if (this->bottom() > winHeight) { // lose
        return false;
    }

    return true;
}

void Circle::updatePosition(float x, float y) {
    shape.setPosition(x, y);
}

float Circle::left() {
    return this->shape.getPosition().x - shape.getRadius();
}

float Circle::right() {
    return this->shape.getPosition().x + shape.getRadius();
}

float Circle::top() {
    return this->shape.getPosition().y - shape.getRadius();
}

float Circle::bottom() {
    return this->shape.getPosition().y + shape.getRadius();
}


void Circle::setPosition(Vector2f position) {
    shape.setPosition({ position.x, position.y - shape.getRadius() + 5.f });
}

Vector2f Circle::getPosition() {
    return shape.getPosition();
}