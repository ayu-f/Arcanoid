#pragma once
#include "Circle.h"

using namespace sf;

class Ball : public Circle {
public:
    Ball(int x, int y);

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    void SpeedUp();
    void SetSpeedDefualt();
    void SpeedDown();
    void FollowPaddle(Vector2f vec);
    void setPosition(Vector2f position);
    void ReflectX();
};

