#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Definitions.h"
#include "GOLoader.h"

GameObject::GameObject(const GOLoader loader) : animation(loader), physics(loader)
{
    moving = false;
}

GameObject::~GameObject() {}

void GameObject::update()
{
    physics.update();

    if (!moving)
    {
        animation.columnFrame = 0;
    }
    animation.update(moving, physics.position.x, physics.position.y);
}

void GameObject::draw()
{
    animation.draw();
}