#pragma once

#include <string>
#include <vector>
#include <list>

#include <SDL.h>

#include "../TextureManager/TextureManager.h"
#include "Layer.h"
#include "TileSet.h"


using TileSetList = std::vector<TileSet>; // List of TileSets
using TileMap = std::vector<std::vector<int>>; // Map of textures IDs

class TileLayer : public Layer
{
private:
    int rowCount;
    int columnCount;
    std::vector<SDL_Texture *> textures;
    TileMap tileMap;
    TileSetList tileSets;

public:
    int tileSize;
    TileLayer(int tileSize, int rowCount, int columnCount, TileMap tileMap, TileSetList tileSets);
    virtual ~TileLayer();

    virtual void draw(const Vector2D &position);
    virtual void update();

    inline int getTilesize();
    inline TileMap getTileMap();
    inline int getRowCount();
    inline int getColCount();
    inline TileSetList getTileSetList();
};