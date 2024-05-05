#include "Player.h"
#include "InputHandler.h"

int x;
int y;

Player::Player(const LoaderParams *params) : GameObject(params), direction(0, 0) {}

void Player::handleInput()
{
    direction.setX(0);
    direction.setY(0);

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
        y += 1;
    }

    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        y -= 1;
    }

    this->direction.setX(x);
    this->direction.setY(y);

    this->direction.normalize();
}

void Player::update()
{
    this->velocity.setX(0);
    this->velocity.setY(0);

    handleInput();

    this->velocity.setX(direction.getX() * 2);
    this->velocity.setY(direction.getY() * -2);

    if (direction.getX() > 0)
    {
        this->rowFrame = 3;
    }
    else if (direction.getX() < 0)
    {
        this->rowFrame = 2;
    }

    if (direction.getY() > 0)
    {
        this->rowFrame = 1;
    }
    else if (direction.getY() < 0)
    {
        this->rowFrame = 0;
    }

    GameObject::update();
}

void Player::draw()
{
    GameObject::draw();
}

void Player::clean()
{
}