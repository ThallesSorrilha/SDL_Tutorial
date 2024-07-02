#include <random>

#include "Enemy.h"
#include "../Timer/Timer.h"

std::random_device seed;
std::uniform_int_distribution<> dis(0, 2);
std::uniform_int_distribution<> dis2(500, 2000);
std::uniform_int_distribution<> dis3(0, 2);

Enemy::Enemy(const GOLoader loader) : GameObject(loader)
{
    type = Type::Enemy;
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
    if (Timer::getGlobal() >= strollTime)
    {
        std::mt19937 gen(seed());

        strollTime = dis2(gen) + Timer::getGlobal();
        direction.x = dis(gen) - 1;
        direction.y = dis(gen) - 1;
        speed = dis3(gen) / 5.0F;
    }
}

void Enemy::collisionResolution(const GameObject &other)
{
}