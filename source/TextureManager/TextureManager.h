#pragma once

#include <SDL.h>

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    static SDL_Texture *loadTexture(const char *filename);
    static void draw(SDL_Texture *texture, const SDL_Rect &srcRect, const SDL_Rect &destRect);
};