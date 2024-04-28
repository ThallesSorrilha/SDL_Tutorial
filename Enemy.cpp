#include "Enemy.h"

Enemy::Enemy(const LoaderParams *params) : GameObject(params) {}

void Enemy::draw()
{
    GameObject::draw();
}

void Enemy::update()
{
    GameObject::update();
    //this->position.setX(position.getX() + 1);
    //this->position.setY(position.getY() + 1);
}

void Enemy::clean()
{
}