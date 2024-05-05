#include <iostream>

#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams *params) : GameObject(params) {}

float x;
float y;

void Player::handleInput()
{
    x = 0;
    y = 0;

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        x += 1;
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        x -= 1;
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        y -= 1;
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        y += 1;
    }

    this->velocity.setX(x * 2);
    this->velocity.setY(y * 2);
}

void Player::update()
{
    this->velocity.setX(0);
    this->velocity.setY(0);

    handleInput();

    GameObject::update();
}

void Player::draw()
{
    GameObject::draw();
}

void Player::clean()
{
}