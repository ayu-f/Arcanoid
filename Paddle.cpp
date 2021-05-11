#include "Paddle.h"

Paddle::Paddle(int x, int y) {
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
    shape.setSize({ this->width, this->height });
    shape.setFillColor(Color::Red);
    shape.setOrigin(width / 2.f, height / 2.f);
}

void Paddle::draw(RenderTarget& target, RenderStates state) const {
    target.draw(this->shape, state);
}

void Paddle::update(float winWidth) {
    this->shape.move(this->velocity);

    if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0) {
        velocity.x = -paddleVelocity;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < winWidth) {
        velocity.x = paddleVelocity;
    }
    else {
        velocity.x = 0.f;
    }
}

Vector2f Paddle::getVelocity() {
    return this->velocity;
}

float Paddle::left() {
    return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Paddle::right() {
    return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Paddle::top() {
    return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Paddle::bottom() {
    return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

void Paddle::IncraseWidth() {
    this->width += 100.f;
    shape.setSize({ this->width, this->height });
    shape.setOrigin(width / 2.f, height / 2.f);
}

Vector2f Paddle::getPosition() {
    return shape.getPosition();
}