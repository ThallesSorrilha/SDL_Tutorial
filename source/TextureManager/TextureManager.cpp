#include <string>

#include <SDL_image.h>

#include "../TextureManager/TextureManager.h"
#include "../Game/Game.h"
#include "../Definitions/Definitions.h"

TextureManager::TextureManager() {}
TextureManager::~TextureManager() {}

SDL_Texture *TextureManager::loadTexture(std::string filename)
{
    SDL_Surface *surface = IMG_Load(filename.c_str());
    if (surface == nullptr)
    {
        std::cout << "Surface error" << std::endl;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    if (texture == nullptr)
    {
        std::cout << "Texture error" << std::endl;
    }

    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::draw(SDL_Texture *texture, const SDL_Rect &srcRect, const SDL_Rect &destRect)
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}

void TextureManager::drawTile(SDL_Texture *texture, int tileSize, int x, int y, int rowFrame, int columnFrame, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    srcRect.x = tileSize * columnFrame;
    srcRect.y = tileSize * rowFrame;
    srcRect.w = tileSize;
    srcRect.h = tileSize;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = tileSize;
    dstRect.h = tileSize;
    SDL_RenderCopyEx(Game::renderer, texture, &srcRect, &dstRect, 0, nullptr, flip);
}