#include "Physics.h"
#include "Definitions.h"

#include <iostream>

Physics::Physics(const GOLoader loader) : force(0, 0), position(loader.xPosition, loader.yPosition), velocity(0, 0), acceleration(0, 0), direction(0, 0)
{
    this->mass = loader.mass;
}

Physics::~Physics() {}

void Physics::update()
{
    Physics::kinematics();
    this->force = 0;
}

void Physics::kinematics()
{
    // std::cout << "force.x:" << this->force.x << " force.y:" << this->force.y << std::endl;

    acceleration = (force - (velocity * (gravity * mass * defaultDynamicFrictionCoefficient))) / mass;
    // std::cout << "acceleration.x:" << this->acceleration.x << " acceleration.y:" << this->acceleration.y << std::endl;

    velocity += (acceleration * defaultFrameDelayinSeconds);
    // std::cout << "velocity.x:" << this->velocity.x << " velocity.y:" << this->velocity.y << std::endl;

    position.x += (velocity.x * defaultFrameDelayinSeconds);
    position.y -= (velocity.y * defaultFrameDelayinSeconds);
    // std::cout << "position.x:" << this->position.x << " position.y:" << this->position.y << std::endl;

    //std::cout << "" << std::endl;
}

bool Physics::isDirect() const
{
    if (std::abs(direction.x) < 0.1F && std::abs(direction.y) < 0.1F)
    {
        return false;
    }
    else
    {
        return true;
    }
}