#include "Player.h"

Player::Player(const LoaderParams *params) : GameObject(params) {}

void Player::draw()
{
    GameObject::draw();
}

void Player::update()
{
    GameObject::update();
    //this->position.setX(position.getX() + 1);
    //this->position.setY(position.getY() + 1);
}

void Player::clean()
{
}