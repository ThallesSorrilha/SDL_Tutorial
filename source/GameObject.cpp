#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Definitions.h"
#include "GOLoader.h"

GameObject::GameObject(const GOLoader loader) : animation(loader), position(loader.xPosition, loader.yPosition)
{
    moving = false;
}

GameObject::~GameObject() {}

void GameObject::update()
{
    if (moving)
    {
        animation.update(position.x, position.y);
    }
    else
    {
        animation.columnFrame = 0;
    }
}

void GameObject::draw()
{
    animation.draw();
}