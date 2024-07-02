#include "Dimension.h"
#include "../Definitions/Definitions.h"

Dimension::Dimension(const GOLoader loader) : position(loader.xPosition, loader.yPosition), size(loader.width, loader.height) {}

Dimension::~Dimension() {}

void Dimension::update(Vector2D velocity)
{
    position.x += velocity.x * defaultFrameDelayinSeconds;
    position.y -= velocity.y * defaultFrameDelayinSeconds;
}

Vector2D Dimension::calculateInvasion(const Dimension &box2)
{
    Vector2D response;

    float rightInvasion = (this->position.x + this->size.x) - box2.position.x;
    float leftInvasion = (box2.position.x + box2.size.x) - this->position.x;
    float bottomInvasion = (this->position.y + this->size.y) - box2.position.y;
    float topInvasion = (box2.position.y + box2.size.y) - this->position.y;

    float smallest = topInvasion;
    if (bottomInvasion <= smallest)
    {
        smallest = bottomInvasion;
    }
    if (leftInvasion <= smallest)
    {
        smallest = leftInvasion;
    }
    if (rightInvasion <= smallest)
    {
        smallest = rightInvasion;
    }

    if (smallest == rightInvasion)
    {
        response.x = -rightInvasion;
    }
    else if (smallest == leftInvasion)
    {
        response.x = leftInvasion;
    }
    else if (smallest == bottomInvasion)
    {
        response.y = -bottomInvasion;
    }
    else if (smallest == topInvasion)
    {
        response.y = topInvasion;
    }

    return response;
}

void Dimension::teleportAbsolute(const Vector2D newPosition)
{
    position = newPosition;
}

void Dimension::teleportRelative(const Vector2D newPosition)
{
    position += newPosition;
}

void Dimension::teleportAbsolute(const float x, const float y)
{
    position.x = x;
    position.x = y;
}

void Dimension::teleportRelative(const float x, const float y)
{
    position.x += x;
    position.x += y;
}