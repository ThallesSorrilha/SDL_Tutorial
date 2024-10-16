#pragma once

#include <string>

#include <SDL.h>

#include "../Definitions/Definitions.h"

struct LoadTS
{
    const std::string tileSrc;
    const int lenX;
    const int lenY;
};

class TileSource
{

public:
    SDL_Texture *tileSrc;
    int lenX;
    int lenY;

    TileSource(LoadTS loadTS);
    ~TileSource();

    static inline LoadTS level1 = {"level1", 4, 3};
};