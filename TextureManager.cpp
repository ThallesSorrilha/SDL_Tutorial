#include "TextureManager.h"

TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager() {}
TextureManager::~TextureManager() {}

bool TextureManager::loadTexture(string fileName, string id, SDL_Renderer *renderer)
{
    SDL_Surface *surface = IMG_Load(fileName.c_str());
    if (surface == nullptr)
    {
        cerr << fileName << " surface error" << endl;
        return false;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr)
    {
        cerr << fileName << " texture error" << endl;
        return false;
    }

    this->textureMap[id] = texture;
    return true;
}

void TextureManager::draw(string textureID, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect playerSrcRect;
    SDL_Rect playerDestRect;

    playerSrcRect.x = 0;
    playerSrcRect.y = 0;

    playerSrcRect.w = playerDestRect.w = width;
    playerSrcRect.h = playerDestRect.h = height;

    playerDestRect.x = x;
    playerDestRect.y = y;

    SDL_RenderCopyEx(renderer, this->textureMap[textureID], &playerSrcRect, &playerDestRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string textureID, int x, int y, int width, int height, int column, int row, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect playerSrcRect;
    SDL_Rect playerDestRect;

    playerSrcRect.x = width * column;
    playerSrcRect.y = height * row;

    playerSrcRect.w = playerDestRect.w = width;
    playerSrcRect.h = playerDestRect.h = height;

    playerDestRect.x = x;
    playerDestRect.y = y;

    SDL_RenderCopyEx(renderer, this->textureMap[textureID], &playerSrcRect, &playerDestRect, 0, 0, flip);
}