#include <random>

#include "Enemy.h"
#include "Definitions.h"

Uint32 strollTime = 0;
int randomNumber1 = 0;
int randomNumber2 = 0;

Enemy::Enemy(const GOLoader loader) : GameObject(loader) {}

void Enemy::update()
{
    Enemy::randomStroll();
    physics.update(direction, 1);
    GameObject::update();
    animation.update(true, physics.position, direction);
    direction = 0;
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
        //std::cout << "strollTime: " << strollTime << std::endl;
        randomNumber1 = dis(gen) - 1;
        //std::cout << "direction.x: " << randomNumber1 << std::endl;
        randomNumber2 = dis(gen) - 1;
        //std::cout << "direction.y: " << randomNumber2 << std::endl;
        //std::cout << "" << std::endl;
    }
    direction.x = randomNumber1;
    //std::cout << "Sustained direction.x: " << direction.x << std::endl;
    direction.y = randomNumber2;
    //std::cout << "Sustained direction.y: " << direction.y << std::endl;
    //std::cout << "" << std::endl;
}