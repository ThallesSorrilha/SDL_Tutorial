#pragma once

#include "../Vector2D/Vector2D.h"

class Layer
{
public:
    virtual void draw(const Vector2D &position) = 0;
    virtual void update() = 0;
};