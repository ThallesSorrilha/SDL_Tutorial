#include "Enemy.h"

Enemy::Enemy(const LoaderParams *params) : GameObject(params) {}

void Enemy::update()
{
    this->velocity.setX(1);
    this->velocity.setY(1);
    GameObject::update();
}

void Enemy::draw()
{
    GameObject::draw();
}

void Enemy::clean()
{
}