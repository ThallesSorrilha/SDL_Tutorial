#include <iostream>

#include "GameObject.h"

GameObject::GameObject(const GOLoader loader) : dimension(loader), direction(0, 0),
                                                physics(loader.mass), animation(loader)
{
    this->attackPt = loader.atack;
    this->maxLife = loader.maxLife;
    this->life = this->maxLife;
    isAttack = false;
}

GameObject::~GameObject() {}

void GameObject::update()
{
    /*if (isDead())
    {
        std::cout << "Algúem Morreu" << std::endl;
        this->clean();
    }*/
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
    std::cout << "Limpando GameObject" << std::endl;
    isDestroyed = true;
    animation.clean();
    this->dimension.~Dimension();
    this->~GameObject();
}

// endereço
void GameObject::collisionResolution(const GameObject &other)
{
}

void GameObject::sufferDamage(const int minus)
{
    life-=minus;
}

bool GameObject::isDead()
{
    if (life <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GameObject::attack()
{
}