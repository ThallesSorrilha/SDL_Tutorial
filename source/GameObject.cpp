#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Definitions.h"
#include "GOLoader.h"

GameObject::GameObject(const GOLoader loader) : dimension(loader), direction(0, 0),
                                                physics(loader.mass), animation(loader) {}

GameObject::~GameObject() {}

void GameObject::update()
{
    dimension.update(physics.velocity);
}

void GameObject::draw() const
{
    animation.draw();
}

bool GameObject::isDirect() const
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

void GameObject::clean() const
{
    animation.clean();
}

void GameObject::collisionResolution(GameObject* other)
{
}