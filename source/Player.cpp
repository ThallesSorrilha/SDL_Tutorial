#include "Player.h"
#include "Definitions.h"

Player::Player(const GOLoader loader, int controlMap[4]) : GameObject(loader), control(controlMap)
{
    animation.gifFrameDelay = 200;
}

void Player::handleInput()
{
    control.handleInput();

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
}

void Player::update()
{
    Player::handleInput();
    physics.update(direction, position, 2);
    GameObject::update();

    bool moving = this->isDirect();
    if (!moving)
    {
        animation.columnFrame = 0;
    }

    animation.update(moving, position, direction);
    animation.face(direction);
    direction = 0;
}

void Player::draw() const
{
    GameObject::draw();
}