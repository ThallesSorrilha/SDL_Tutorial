#pragma once

#include <SDL.h>

#include "Definitions.h"

class Map
{
private:
    SDL_Rect src, dest;
    SDL_Texture *grass, *water, *dirt;

    int map[defaultHeightBlocks][defaultWidthBlocks];

public:
    Map(int arr[defaultHeightBlocks][defaultWidthBlocks]);
    ~Map();

    void loadMap(int arr[defaultHeightBlocks][defaultWidthBlocks]);
    void gifMap();
    void updateMap();
    void drawMap();
};