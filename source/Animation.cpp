#include "Animation.h"
#include "TextureManager.h"

#include <iostream>

Animation::Animation(const GOLoader loader)
{
    texture = TextureManager::loadTexture(loader.textureSheet);

    srcRect.x = srcRect.y = 0;
    srcRect.w = (int)loader.width;
    srcRect.h = (int)loader.height;

    destRect.x = (int)loader.xPosition;
    destRect.y = (int)loader.yPosition;
    destRect.w = (int)loader.width;
    destRect.h = (int)loader.height;
}

Animation::~Animation() {}

void Animation::update(const int positionX, const int positionY)
{
    Animation::gif();
    srcRect.x = columnFrame * defaultBlockSize;
    srcRect.y = rowFrame * defaultBlockSize;
    destRect.x = positionX;
    destRect.y = positionY;
}

void Animation::draw()
{
    TextureManager::draw(texture, srcRect, destRect);
}

void Animation::gif()
{
    columnFrame = int(SDL_GetTicks() / gifFrameDelay) % gifSteps;
}