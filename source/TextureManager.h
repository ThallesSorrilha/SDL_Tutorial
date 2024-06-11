#pragma once

#include <SDL.h>

#include "Game.h"

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    static SDL_Texture *loadTexture(const char *filename);
    static void draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect);
};