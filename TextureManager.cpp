#include <iostream>

#include <SDL_image.h>

#include "TextureManager.h"
#include "Debug.h"

TextureManager *TextureManager::instance = nullptr;

TextureManager::TextureManager() {}
TextureManager::~TextureManager() {}

SDL_Texture* TextureManager::loadTexture(const std::string fileName, SDL_Renderer *renderer)
{
    SDL_Surface *surface = IMG_Load(fileName.c_str());
    if (surface == nullptr)
    {
        criticalError(fileName + " surface error");
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr)
    {
        criticalError(fileName + " texture error");
    }

    return texture;
}

void TextureManager::draw(SDL_Texture* textureID, const int x, const int y, const int width, const int height, SDL_Renderer *renderer, const SDL_RendererFlip flip)
{
    SDL_Rect playerSrcRect;
    SDL_Rect playerDestRect;

    playerSrcRect.x = 0;
    playerSrcRect.y = 0;

    playerSrcRect.w = playerDestRect.w = width;
    playerSrcRect.h = playerDestRect.h = height;

    playerDestRect.x = x;
    playerDestRect.y = y;

    SDL_RenderCopyEx(renderer, textureID, &playerSrcRect, &playerDestRect, 0, 0, flip);
}

void TextureManager::drawFrame(SDL_Texture* textureID, const int x, const int y, const int width, const int height, const int column, const int row, SDL_Renderer *renderer, const SDL_RendererFlip flip)
{
    SDL_Rect playerSrcRect;
    SDL_Rect playerDestRect;

    playerSrcRect.x = width * column;
    playerSrcRect.y = height * row;

    playerSrcRect.w = playerDestRect.w = width;
    playerSrcRect.h = playerDestRect.h = height;

    playerDestRect.x = x;
    playerDestRect.y = y;

    // resolver com ponteiros, diretamente
    SDL_RenderCopyEx(renderer, textureID, &playerSrcRect, &playerDestRect, 0, 0, flip);
}