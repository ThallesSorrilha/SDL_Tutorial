#include <iostream>

#include "Player.h"
#include "InputHandler.h"

Player::Player(const GOLoader loader) : GameObject(loader)
{
    animation.gifFrameDelay = 200;
}

void Player::handleInput()
{
    control.x = 0;
    control.y = 0;

    int x = 0;
    int y = 0;

    moving = true;

    if (InputHandler::isKeyDown(SDL_SCANCODE_RIGHT))
    {
        x += 1;
        animation.rowFrame = 3;
    }

    if (InputHandler::isKeyDown(SDL_SCANCODE_LEFT))
    {
        x -= 1;
        animation.rowFrame = 2;
    }

    if (InputHandler::isKeyDown(SDL_SCANCODE_UP))
    {
        y += 1;
        animation.rowFrame = 1;
    }

    if (InputHandler::isKeyDown(SDL_SCANCODE_DOWN))
    {
        y -= 1;
        animation.rowFrame = 0;
    }

    control.x = x;
    control.y = y;

    if (x == 0 && y == 0)
    {
        moving = false;
    }

    control.normalize(1);
}

void Player::update()
{
    handleInput();

    GameObject::update();

    position.x += control.x * 2;
    position.y += control.y * -2;
}

void Player::draw()
{
    GameObject::draw();
}