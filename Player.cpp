#include "Player.h"

Player::Player(const LoaderParams *params) : GameObject(params) {}

void Player::draw()
{
    GameObject::draw();
}

void Player::update()
{
    GameObject::update();
}

void Player::clean()
{
}