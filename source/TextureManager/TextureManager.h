#pragma once

#include <string>
#include <vector>

#include <SDL.h>

class TextureManager
{
public:
    static SDL_Texture *loadTexture(std::string filename);
    static void draw(SDL_Texture *texture, const SDL_Rect &srcRect, const SDL_Rect &destRect);
    static void drawTile(SDL_Texture *texture, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
};