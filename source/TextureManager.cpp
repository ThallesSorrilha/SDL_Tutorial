#include <SDL_image.h>

#include "TextureManager.h"

TextureManager::TextureManager() {}
TextureManager::~TextureManager() {}

SDL_Texture *TextureManager::loadTexture(const char *filename)
{
    SDL_Surface *surface = IMG_Load(filename);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::draw(SDL_Texture *texture, SDL_Rect srcRect, SDL_Rect destRect)
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}