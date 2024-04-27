#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"

GameObject::GameObject(const LoaderParams *params)
{
    this->xPosition = params->getXPosition();
    this->yPosition = params->getYPosition();
    this->width = params->getWidth();
    this->height = params->getHeight();
    this->textureID = params->getTextureID();
    this->columnFrame = 0;
    this->rowFrame = 0;
}

void GameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(this->textureID, this->xPosition, this->yPosition, this->width, this->height, this->columnFrame, this->rowFrame, TheGame::Instance()->getRenderer());
}

void GameObject::update()
{
    this->columnFrame = (int(SDL_GetTicks() / 250) % 4);
}

void GameObject::clean()
{
}