#include "Collision.h"

Collision::Collision() {}

Collision::~Collision() {}

bool Collision::checkCollision(const Dimension &box1, const Dimension &box2)
{
    if ((box2.position.x + box2.size.x < box1.position.x))
    {
        return false;
    }

    if ((box1.position.x + box1.size.x < box2.position.x))
    {
        return false;
    }

    if ((box2.position.y + box2.size.y < box1.position.y))
    {
        return false;
    }

    if ((box1.position.y + box1.size.y < box2.position.y))
    {
        return false;
    }

    return true;
}