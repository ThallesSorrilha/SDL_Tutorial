#pragma once

#include "Vector2D.h"
#include "GOLoader.h"

class Physics
{
public:
    Vector2D direction;
    Vector2D position;
    Vector2D force;
    float mass;
    Vector2D velocity;
    Vector2D acceleration;

    Physics(const GOLoader loader);
    ~Physics();

    void update();
    void kinematics();
    bool isDirect() const;
};