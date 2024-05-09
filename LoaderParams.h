#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include <SDL.h>
#include <SDL_image.h>

struct LoaderParams
{
    float xPosition;
    float yPosition;
    float width;
    float height;
    SDL_Texture* textureID;
};

#endif