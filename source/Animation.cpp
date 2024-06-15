#include <cmath>

#include "Animation.h"
#include "TextureManager.h"
#include "Definitions.h"

Animation::Animation(const GOLoader loader)
{
    texture = TextureManager::loadTexture(loader.textureSheet);

    srcRect.x = srcRect.y = 0;
    srcRect.w = std::round(loader.width * defaultBlockSize);
    srcRect.h = std::round(loader.height * defaultBlockSize);

    destRect.x = std::round(loader.xPosition * defaultBlockSize);
    destRect.y = std::round(loader.yPosition * defaultBlockSize);
    destRect.w = std::round(loader.width * defaultBlockSize);
    destRect.h = std::round(loader.height * defaultBlockSize);
}

Animation::~Animation() {}

void Animation::update(const bool gif, const float positionX, const float positionY)
{
    if (gif)
    {
        Animation::gif();
    }
    srcRect.x = columnFrame * defaultBlockSize;
    srcRect.y = rowFrame * defaultBlockSize;
    destRect.x = std::round(positionX * defaultBlockSize);
    destRect.y = std::round(positionY * defaultBlockSize);
}

void Animation::draw()
{
    TextureManager::draw(texture, srcRect, destRect);
}

void Animation::gif()
{
    columnFrame = int(SDL_GetTicks() / gifFrameDelay) % gifSteps;
}