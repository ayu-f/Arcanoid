#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Circle : public GameObject, public Drawable {
protected:
    CircleShape shape;
    float ballRadius = 8.f;
    float ballVelocity = 6.f;
    Vector2f velocity = { ballVelocity, ballVelocity };
    Color color = Color::White;

    void draw(RenderTarget& target, RenderStates state) const;
public:
    Circle(int x, int y);

    bool update(unsigned int winWidth, unsigned int winHeight);
    void updatePosition(float x, float y);
    void setPosition(Vector2f position);

    virtual Vector2f getPosition();
    virtual float left();
    virtual float right();
    virtual float top();
    virtual float bottom();
};