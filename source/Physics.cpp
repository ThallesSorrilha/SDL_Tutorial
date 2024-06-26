#include "Physics.h"
#include "Definitions.h"

#include <iostream>

Physics::Physics(float mass) : force(0, 0), velocity(0, 0), acceleration(0, 0)
{
    this->mass = mass;
}

Physics::~Physics() {}

void Physics::update(Vector2D &direction, float defaultSpeed)
{
    Physics::directionInForce(direction, defaultSpeed);
    Physics::kinematics();
    force = 0;
}

void Physics::kinematics()
{
    // std::cout << "force.x:" << this->force.x << " force.y:" << this->force.y << std::endl;

    // acceleration = (force - (velocity * (gravity * mass * defaultDynamicFrictionCoefficient))) / mass;
    acceleration = ((force / mass) - (velocity * (gravity * defaultDynamicFrictionCoefficient)));
    // std::cout << "acceleration.x:" << this->acceleration.x << " acceleration.y:" << this->acceleration.y << std::endl;

    velocity += (acceleration * defaultFrameDelayinSeconds);
    // std::cout << "velocity.x:" << this->velocity.x << " velocity.y:" << this->velocity.y << std::endl;

    // std::cout << "" << std::endl;
}

void Physics::directionInForce(Vector2D &direction, float defaultSpeed)
{
    direction.normalize(1);
    force += direction * (mass * gravity * defaultDynamicFrictionCoefficient * defaultSpeed);
}