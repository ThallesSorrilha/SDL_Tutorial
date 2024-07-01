// Tile Map ser uma matriz de objetos do jogo

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

    void load(const int arr[defaultHeightBlocks][defaultWidthBlocks]);
    void gif();
    void update();
    void draw();
    void clean() const;
};