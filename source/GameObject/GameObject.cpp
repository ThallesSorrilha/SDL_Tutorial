#include <iostream>

#include "GameObject.h"

GameObject::GameObject(const GOLoader loader) : dimension(loader), direction(0, 0),
                                                physics(loader.mass), animation(loader)
{
    this->atack = loader.atack;
    this->maxLife = loader.maxLife;
    this->life = this->maxLife;
}

GameObject::~GameObject() {}

void GameObject::update()
{
    if (isDead())
    {
        GameObject::clean();
    }
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

void GameObject::clean()
{
    animation.clean();
}

// endereço
void GameObject::collisionResolution(const GameObject &other)
{
}

void GameObject::sufferDamage()
{
    life--;
}

bool GameObject::isDead()
{
    if (!life > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}