#pragma once

#include <SDL.h>

#include "GOLoader.h"
#include "Definitions.h"

class Animation
{
public:
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    int columnFrame = 0;
    int rowFrame = 0;
    int gifFrameDelay = defaultGifFrameDelay;
    int gifSteps = defaultGifSteps;

    Animation(const GOLoader loader);
    ~Animation();

    void update(const bool gif, const float positionX, const float positionY);
    void draw();
    void gif();
};