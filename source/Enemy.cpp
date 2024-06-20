#include "Enemy.h"

Enemy::Enemy(const GOLoader loader) : GameObject(loader)
{
    moving = true;
}

void Enemy::update()
{
    physics.addForce(force, 10, 10);
    GameObject::update();
}

void Enemy::draw()
{
    GameObject::draw();
}