#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, float blockWidth, float blockHeight) {
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
    shape.setSize(Vector2f{ blockWidth, blockHeight });
    shape.setFillColor(Color(169, 169, 169));
    shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
}

void Rectangle::draw(RenderTarget& target, RenderStates state) const {
    target.draw(this->shape, state);
}

float Rectangle::left() {
    return this->shape.getPosition().x - shape.getSize().x / 2.0f;
}

float Rectangle::right() {
    return this->shape.getPosition().x + shape.getSize().x / 2.0f;
}

float Rectangle::top() {
    return this->shape.getPosition().y - shape.getSize().y / 2.0f;
}

float Rectangle::bottom() {
    return this->shape.getPosition().y + shape.getSize().y / 2.0f;
}

Vector2f Rectangle::getPosition() {
    return shape.getPosition();
}

bool Rectangle::isDestroyed() {
    return this->destroyed;
}

void Rectangle::destroy() {
    this->destroyed = true;
}

Vector2f Rectangle::getSize() {
    return shape.getSize();
}