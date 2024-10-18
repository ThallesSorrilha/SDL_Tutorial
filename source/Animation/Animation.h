#pragma once

#include <SDL.h>

#include "../GOLoader/GOLoader.h"
#include "../Vector2D/Vector2D.h"

class Animation
{
public:
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    int columnFrame;
    int rowFrame;
    int gifFrameDelay;
    int gifSteps;

    Animation(const GOLoader loader);
    Animation(const char *textureSheet, const float xPosition, const float yPosition, const float width, const float height, const int rowFrame);
    ~Animation();

    void update();
    void update(const bool gif, const Vector2D &position, const Vector2D &direction);
    void draw() const;
    void gif();

    void face(const Vector2D &direction);
    void clean();
};