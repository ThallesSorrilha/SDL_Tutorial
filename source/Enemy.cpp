#include "Enemy.h"

Enemy::Enemy(const GOLoader loader) : GameObject(loader)
{
    moving = true;
}

void Enemy::update()
{
    position.x += 0.01;
    position.y += 0.01;
    GameObject::update();
}

void Enemy::draw()
{
    GameObject::draw();
}