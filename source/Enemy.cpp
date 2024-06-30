#include <random>

#include "Enemy.h"
#include "Definitions.h"

Enemy::Enemy(const GOLoader loader) : GameObject(loader)
{
    type = 1;
}

void Enemy::update()
{
    Enemy::randomStroll();
    physics.update(direction, speed);

    GameObject::update();

    animation.update(true, dimension.position, direction);
}

void Enemy::draw() const
{
    GameObject::draw();
}

void Enemy::randomStroll()
{
    if (SDL_GetTicks() >= strollTime)
    {
        std::random_device seed;
        std::mt19937 gen(seed());

        std::uniform_int_distribution<> dis(0, 2);
        std::uniform_int_distribution<> dis2(500, 2000);
        std::uniform_int_distribution<> dis3(0, 2);

        strollTime = dis2(gen) + SDL_GetTicks();
        direction.x = dis(gen) - 1;
        direction.y = dis(gen) - 1;
        speed = dis3(gen) / 5.0F;
    }
}

void Enemy::collisionResolution(GameObject *other)
{
}