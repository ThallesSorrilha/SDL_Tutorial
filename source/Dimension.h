#pragma once

#include "GOLoader.h"
#include "Vector2D.h"

class Dimension
{
public:
    Vector2D position;
    Vector2D size;

    void update(Vector2D velocity);

    Dimension(const GOLoader loader);
    ~Dimension();
};