#pragma once

#include <string>

/*
TileSet - it's the source image, divided into blocks
*/
struct TileSet
{
    int firstID; // first ID of TileSet
    int lastID; // last ID of TileSet
    int rowCount; // rows of the TileSet
    int columnCount; // columns of the TileSet
    int tileCount; // amount of blocks
    int tileSize; // size of the tile (block)
    std::string source; // image source location
};