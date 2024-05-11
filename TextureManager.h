#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <map>

#include <SDL.h>

class TextureManager
{

private:

    static TextureManager *instance;
    TextureManager();
    ~TextureManager();

public:
    
    static TextureManager *Instance()
    {
        if (instance == nullptr)
        {
            instance = new TextureManager();
        }
        return instance;
    }

    /*
    Loads a texture from a source image

    params:
    fileName - source of the image
    renderer - renderer

    return:
    SDL_Texture* - a pointer to the texture
    */
    SDL_Texture* loadTexture(const std::string fileName, SDL_Renderer *renderer);

    /*
    params:
    textureID - pointer to the the texture
    x - x position to start printing on the screen
    y - y position to start printing on the screen
    width - width to print from the source image
    height - height to print from the source image
    renderer - renderer
    flip - see flags for flips
    */
    void draw(SDL_Texture* textureID, const int x, const int y, const int width, const int height, SDL_Renderer *renderer, const SDL_RendererFlip flip = SDL_FLIP_NONE);

    /*
    params:
    textureID - pointer to the the texture
    x - x position to start printing the final rectangle on the screen
    y - y position to start printing the final rectangle on the screen
    width - width of the final rectangle
    height - height of the final rectangle
    row - row of the spritesheet
    collum - collum of the spritesheet
    renderer - renderer
    flip - see flags for flips
    */
    void drawFrame(SDL_Texture* textureID, const int x, const int y, const int width, const int height, const int column, const int row, SDL_Renderer *renderer, const SDL_RendererFlip flip = SDL_FLIP_NONE);
};

typedef TextureManager TheTextureManager;

#endif