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

    moving = true; // retirar

    control.handleInput();

    if (control.right)
    {
        x += 1;
        animation.rowFrame = 3; // mudar
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

    if (direction.length() == 0) // legado
    {
        moving = false;
    }

    direction.normalize(1);

    physics.force += direction * physics.mass * 18;
}

void Player::update()
{
    Player::handleInput();
    GameObject::update();
}

void Player::draw()
{
    GameObject::draw();
}