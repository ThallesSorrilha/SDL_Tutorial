#include "Player.h"
#include "../Definitions/Definitions.h"
#include "../Shot/Shot.h"

#include "../Game/Game.h"

#include <iostream>

bool pastState = false;

Player::Player(const GOLoader loader, int controlMap[5]) : GameObject(loader), control(controlMap), timeAttack()
{
    animation.gifFrameDelay = 200;
    type = Type::Player;
    isAttack = false;
}

void Player::handleInput()
{
    control.handleInput();

    direction = 0;

    if (control.right)
    {
        direction.x += 1;
    }
    if (control.left)
    {
        direction.x -= 1;
    }
    if (control.up)
    {
        direction.y += 1;
    }
    if (control.down)
    {
        direction.y -= 1;
    }
    if (control.attack)
    {
        direction = 0;
        attack();
    }
}

void Player::update()
{
    Player::handleInput();
    physics.update(direction, 2);

    GameObject::update();

    bool moving = this->isDirect();
    if (!moving)
    {
        animation.columnFrame = 0;
    }
    else
    {
        animation.face(direction);
    }

    isAttack = verifyAttack();
    /*std::cout << "---" << std::endl;
    std::cout << "past: " << pastState << std::endl;
    std::cout << "pres: " << isAttack << std::endl;
    std::cout << "---" << std::endl;*/
    if (isAttack)
    {
        animation.columnFrame = 4;

        if (!pastState)
        {
            // std::cout << "Novo Fogo" << std::endl;

            float x, y, w, h, row;
            w = h = 1;
            switch (animation.rowFrame)
            {
            case 0:
                x = dimension.position.x;
                y = dimension.position.y + 1;
                row = 0;
                break;

            case 1:
                x = dimension.position.x;
                y = dimension.position.y - 1;
                row = 1;
                break;

            case 2:
                x = dimension.position.x - 1;
                y = dimension.position.y;
                row = 2;
                break;

            case 3:
                x = dimension.position.x + 1;
                y = dimension.position.y;
                row = 3;
                break;

            default:
                break;
            }

            /*std::cout << "x: " << x << std::endl;
            std::cout << "y: " << y << std::endl;
            std::cout << "w: " << w << std::endl;
            std::cout << "h: " << h << std::endl;
            std::cout << "row: " << row << std::endl;*/
            Game::playerShots.push_back(new Shot("assets/sprites/Fire.png", x, y, w, h, row));
            // std::cout << "!Novo Fogo!" << std::endl;
        }
    }
    pastState = isAttack;

    animation.update(moving, dimension.position, direction);
}

void Player::draw() const
{
    GameObject::draw();
}

void Player::collisionResolution(const GameObject &other)
{
    if (other.type == Type::Enemy)
    {
        Vector2D impact = dimension.calculateInvasion(other.dimension);
        impact.normalize();
        impact /= 2;
        dimension.teleportRelative(impact);
        sufferDamage();
    }
}

void Player::attack()
{
    bool at = verifyAttack();
    if (!at)
    {
        timeAttack.scheduleEvent(0, 200);
    }
}

bool Player::verifyAttack()
{
    bool at = timeAttack.isEventPresent();
    return at;
}