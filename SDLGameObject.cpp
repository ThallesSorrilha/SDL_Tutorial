#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams *params) : GameObject(params)
{
    xPosition = params->getXPosition();
    yPosition = params->getYPosition();
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();
    columnFrame = 0;
    rowFrame = 0;
}

void SDLGameObject::draw()
{
    TheTextureManager::Instance()->drawFrame(textureID, xPosition, yPosition, width, height, columnFrame, rowFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
}

void SDLGameObject::clean()
{
}