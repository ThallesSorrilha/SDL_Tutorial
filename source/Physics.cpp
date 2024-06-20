#include "Physics.h"
#include "Definitions.h"

//
#include <iostream>

Physics::Physics(float mass) : velocity(0, 0), acceleration(0, 0)
{
    this->mass = mass;
}

Physics::~Physics() {}

void Physics::update(Vector2D &force, Vector2D &position)
{
    Physics::kinematics(force, position);
    force = 0;
}

void Physics::addForce(Vector2D &force, Vector2D add)
{
    force += add;
}

void Physics::addForce(Vector2D &force, float x, float y)
{
    force.x += x;
    force.y += y;
}

void Physics::kinematics(Vector2D &force, Vector2D &position)
{
    acceleration = (force - (velocity * defaultDynamicFrictionCoefficient)) / mass;

    /*
        acceleration = force / mass;
        std::cout << "acceleration.x("<<acceleration.x<<") = force.x("<<force.x<<") * mass("<<mass<<");" << std::endl;
    */

    velocity += acceleration * defaultFrameDelayinSeconds;
    std::cout << "velocity.x(" << velocity.x << ") += acceleration.x(" << acceleration.x << ") * defaultFrameDelayinSeconds(" << defaultFrameDelayinSeconds << ");" << std::endl;

    float sav = position.x;
    position.x += velocity.x * defaultFrameDelayinSeconds;
    position.y -= velocity.y * defaultFrameDelayinSeconds;
    std::cout << "position.x(" << position.x << ") = position.x(" << sav << ") + velocity.x(" << velocity.x << ") * defaultFrameDelayinSeconds(" << defaultFrameDelayinSeconds << ");" << std::endl;

    std::cout << "" << std::endl;
}

// 0,03053