#include "Enemy.h"

Enemy::Enemy(const GOLoader loader) : GameObject(loader)
{
    moving = true;
}

void Enemy::update()
{
    force.x = 10;
    force.y = 10;
    GameObject::update();
}

void Enemy::draw()
{
    GameObject::draw();
}