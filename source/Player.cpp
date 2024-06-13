#include <iostream>

#include "Player.h"

Player::Player(const GOLoader loader, int controlMap[4]) : GameObject(loader), control(controlMap)
{
    animation.gifFrameDelay = 200;
}

void Player::handleInput()
{
    direction.x = 0;
    direction.y = 0;

    int x = 0;
    int y = 0;

    moving = true;

    control.handleInput();

    if (control.right)
    {
        x += 1;
        animation.rowFrame = 3;
    }

    if (control.left)
    {
        x -= 1;
        animation.rowFrame = 2;
    }

    if (control.up)
    {
        y += 1;
        animation.rowFrame = 1;
    }

    if (control.down)
    {
        y -= 1;
        animation.rowFrame = 0;
    }

    direction.x = x;
    direction.y = y;

    if (direction.length() == 0)
    {
        moving = false;
    }

    direction.normalize(1);
}

void Player::update()
{
    handleInput();

    GameObject::update();

    position.x += direction.x * 2;
    position.y += direction.y * -2;
}

void Player::draw()
{
    GameObject::draw();
}