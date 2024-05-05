#include "Enemy.h"

Enemy::Enemy(const LoaderParams *params) : GameObject(params) {}

void Enemy::update()
{
    this->velocity.setX(0.2);
    this->velocity.setY(0);
    GameObject::update();
}

void Enemy::draw()
{
    GameObject::draw();
}

void Enemy::clean()
{
}