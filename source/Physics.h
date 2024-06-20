#pragma once

#include "Vector2D.h"

class Physics
{
public:
    Vector2D velocity;
    Vector2D acceleration;
    float mass;

    Physics(float mass);
    ~Physics();

    void update(Vector2D &force, Vector2D &position);
    void addForce(Vector2D &force, Vector2D add);
    void addForce(Vector2D &force, float x, float y);
    void kinematics(Vector2D &force, Vector2D &position);
};