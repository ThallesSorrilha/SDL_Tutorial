#include "Player.h"

inline Player::Player(const LoaderParams *params) : SDLGameObject(params) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    this->columnFrame = (int(SDL_GetTicks() / 100) % 4);
}

void Player::clean()
{
}