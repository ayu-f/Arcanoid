#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual sf::Vector2f getPosition() = 0;

    virtual float left() = 0;
    virtual float right() = 0;
    virtual float top() = 0;
    virtual float bottom() = 0;
};