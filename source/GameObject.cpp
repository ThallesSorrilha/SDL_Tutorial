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