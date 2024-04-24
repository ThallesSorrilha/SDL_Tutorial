#include "Enemy.h"

Enemy::Enemy(const LoaderParams *params) : SDLGameObject(params) {}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    this->columnFrame = (int(SDL_GetTicks() / 100) % 4);
}

void Enemy::clean()
{
}