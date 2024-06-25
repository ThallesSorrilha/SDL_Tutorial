#pragma once

#include "Vector2D.h"

class Physics
{
public:
    Vector2D force;
    float mass;

    Vector2D acceleration;
    Vector2D velocity;

    Physics(float mass);
    ~Physics();

    void update(Vector2D &direction, Vector2D &position, float defaultSpeed);
    void kinematics(Vector2D &position);
    void directionInForce(Vector2D &direction, float defaultSpeed);
};