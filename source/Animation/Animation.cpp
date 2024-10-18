#include "Animation.h"
#include "../TextureManager/TextureManager.h"
#include "../Definitions/Definitions.h"

Animation::Animation(const GOLoader loader)
{
    texture = TextureManager::loadTexture(loader.textureSheet);

    srcRect.x = srcRect.y = 0;
    srcRect.w = std::round(loader.width * defaultSpriteUnit);
    srcRect.h = std::round(loader.height * defaultSpriteUnit);

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

    srcRect.x = columnFrame * defaultSpriteUnit;
    srcRect.y = rowFrame * defaultSpriteUnit;
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

void Animation::clean()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }
}