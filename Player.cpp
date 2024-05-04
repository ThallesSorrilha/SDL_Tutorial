#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams *params) : GameObject(params) {}

void Player::draw()
{
    GameObject::draw();
}

void Player::update()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        velocity.setX(1);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        velocity.setX(-1);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        velocity.setY(-1);
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        velocity.setY(1);
    }

    GameObject::update();
}

void Player::clean()
{
}