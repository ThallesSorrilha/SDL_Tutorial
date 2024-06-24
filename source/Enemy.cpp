#include "Enemy.h"

Enemy::Enemy(const GOLoader loader) : GameObject(loader) {}

void Enemy::update()
{
    physics.force += 1000;
    GameObject::update();
}

void Enemy::draw() const
{
    GameObject::draw();
}