#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Definitions.h"
#include "GOLoader.h"

GameObject::GameObject(const GOLoader loader) : animation(loader), physics(loader) {}

GameObject::~GameObject() {}

void GameObject::update()
{
    physics.update();

    bool moving = physics.isDirect();
    if (!moving)
    {
        animation.columnFrame = 0;
    }
    animation.update(moving, physics.position, physics.direction);
}

void GameObject::draw() const
{
    animation.draw();
}