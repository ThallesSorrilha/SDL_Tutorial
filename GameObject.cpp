#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"

GameObject::GameObject(const LoaderParams& params) : position(params.xPosition, params.yPosition), velocity(0, 0), acceleration(0, 0)
{
    this->width = params.width;
    this->height = params.height;
    this->textureID = params.textureID;
    this->columnFrame = 0;
    this->rowFrame = 0;
}

void GameObject::update()
{
    this->columnFrame = (int(SDL_GetTicks() / 250) % 4);
    this->position += this->velocity;
    this->velocity += this->acceleration;
}

void GameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(this->textureID, (int)this->position.getX(), (int)this->position.getY(), this->width, this->height, this->columnFrame, this->rowFrame, TheGame::Instance()->getRenderer());
}

void GameObject::clean()
{
}