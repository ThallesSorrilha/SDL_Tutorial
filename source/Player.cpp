#include "Player.h"
#include "Definitions.h"

Player::Player(const GOLoader loader, int controlMap[4]) : GameObject(loader), control(controlMap)
{
    animation.gifFrameDelay = 200;
}

void Player::handleInput()
{
    physics.direction = 0;

    control.handleInput();

    if (control.right)
    {
        physics.direction.x += 1;
    }
    if (control.left)
    {
        physics.direction.x -= 1;
    }
    if (control.up)
    {
        physics.direction.y += 1;
    }
    if (control.down)
    {
        physics.direction.y -= 1;
    }

    physics.direction.normalize(1);

    physics.force += physics.direction * (physics.mass * gravity * 4);
}

void Player::update()
{
    Player::handleInput();
    GameObject::update();
}

void Player::draw() const
{
    GameObject::draw();
}