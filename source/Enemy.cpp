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
    physics.update(direction, 0.4F);

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

        strollTime = dis2(gen) + SDL_GetTicks();
        // std::cout << "strollTime: " << strollTime << std::endl;
        direction.x = dis(gen) - 1;
        // std::cout << "direction.x: " << randomNumber1 << std::endl;
        direction.y = dis(gen) - 1;
        // std::cout << "direction.y: " << randomNumber2 << std::endl;
        // std::cout << "" << std::endl;
    }
}

void Enemy::collisionResolution(GameObject *other)
{
}