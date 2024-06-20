#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Definitions.h"
#include "GOLoader.h"

GameObject::GameObject(const GOLoader loader) : animation(loader), physics(loader.mass), position(loader.xPosition, loader.yPosition), force(0, 0)
{
    moving = false;
}

GameObject::~GameObject() {}

void GameObject::update()
{
    physics.update(force, position);

    if (!moving)
    {
        animation.columnFrame = 0;
    }
    animation.update(moving, position.x, position.y);
}

void GameObject::draw()
{
    animation.draw();
}