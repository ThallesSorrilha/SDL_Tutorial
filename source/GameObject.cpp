#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Definitions.h"
#include "GOLoader.h"

GameObject::GameObject(const GOLoader loader) : animation(loader), physics(loader), direction(0, 0) {}

GameObject::~GameObject() {}

void GameObject::update()
{
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