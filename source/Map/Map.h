#pragma once

#include <string>

#include <SDL.h>

#include "../Definitions/Definitions.h"
#include "../TileSource/TileSource.h"

class Map
{
private:
    SDL_Rect src, dest;
    TileSource tileSource;

    int map[defaultHeightBlocks][defaultWidthBlocks];

public:
    Map(const int arr[defaultHeightBlocks][defaultWidthBlocks], LoadTS loadts);
    ~Map();

    void load(const int arr[defaultHeightBlocks][defaultWidthBlocks]);
    void gif();
    void update();
    void draw();
    void clean() const;
};