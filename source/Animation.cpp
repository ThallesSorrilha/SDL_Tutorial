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

    columnFrame = 0;
    rowFrame = 0;
    gifFrameDelay = defaultGifFrameDelay;
    gifSteps = defaultGifSteps;
}

Animation::~Animation() {}

void Animation::update(const bool gif, const Vector2D &position, const Vector2D &direction)
{
    if (gif)
    {
        Animation::gif();
    }

    srcRect.x = columnFrame * defaultBlockSize;
    srcRect.y = rowFrame * defaultBlockSize;
    destRect.x = std::round(position.x * defaultBlockSize);
    destRect.y = std::round(position.y * defaultBlockSize);
}

void Animation::draw() const
{
    TextureManager::draw(texture, srcRect, destRect);
}

void Animation::gif()
{
    columnFrame = int(SDL_GetTicks() / gifFrameDelay) % gifSteps;
}

void Animation::face(const Vector2D &direction)
{
    if (direction.x > 0)
    {
        rowFrame = 3;
    }
    if (direction.x < 0)
    {
        rowFrame = 2;
    }
    if (direction.y > 0)
    {
        rowFrame = 1;
    }
    if (direction.y < 0)
    {
        rowFrame = 0;
    }
}

void Animation::clean() const
{
    SDL_DestroyTexture(texture);
}