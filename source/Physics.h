#pragma once

#include "Vector2D.h"
#include "GOLoader.h"

class Physics
{
public:
    Vector2D position;
    Vector2D force;
    float mass;
    Vector2D velocity;
    Vector2D acceleration;

    Physics(const GOLoader loader);
    ~Physics();

    void update(const Vector2D direction, float defaultSpeed);
    void kinematics();
    void directionInForce(Vector2D direction, float defaultSpeed);
};