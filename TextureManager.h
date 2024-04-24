#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_image.h>

#include <map>

#include "Utilities.h"

class TextureManager
{

private:
    /*
    Correlate an alias to a texture
    */
    std::map<string, SDL_Texture *> textureMap;

    TextureManager();
    static TextureManager *instance;

public:
    ~TextureManager();
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
    id - create an alias
    renderer - renderer

    return:
    (bool) - true if the image loads correcly
    */
    bool loadTexture(string fileName, string textureID, SDL_Renderer *renderer);

    /*
    params:
    id - alias of the texture
    x - x position to start printing on the screen
    y - y position to start printing on the screen
    width - width to print from the source image
    height - height to print from the source image
    renderer - renderer
    flip - see flags for flips
    */
    void draw(string textureID, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    /*
    params:
    id - alias of the texture
    x - x position to start printing the final rectangle on the screen
    y - y position to start printing the final rectangle on the screen
    width - width of the final rectangle
    height - height of the final rectangle
    row - row of the spritesheet
    collum - collum of the spritesheet
    renderer - renderer
    flip - see flags for flips
    */
    void drawFrame(string textureID, int x, int y, int width, int height, int column, int row, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

typedef TextureManager TheTextureManager;

#endif