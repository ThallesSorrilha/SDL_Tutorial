#include "Enemy.h"

Enemy::Enemy(const LoaderParams *params) : GameObject(params) {}

void Enemy::draw()
{
    GameObject::draw();
}

void Enemy::update()
{
    GameObject::update();
}

void Enemy::clean()
{
}