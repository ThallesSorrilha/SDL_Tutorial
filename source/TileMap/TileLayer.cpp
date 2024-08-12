#include <iostream>

#include "TileLayer.h"
#include "../TextureManager/TextureManager.h"
#include <string>

TileLayer::TileLayer(int tileSize, int rowCount, int columnCount, TileMap tileMap, TileSetList tileSets)
{
    this->tileSize = tileSize;
    this->rowCount = rowCount;
    this->columnCount = columnCount;
    this->tileMap = tileMap;
    this->tileSets = tileSets;

    for (unsigned int i = 0; i < this->tileSets.size(); i++)
    {
        textures.push_back(TextureManager::loadTexture(std::string("assets/maps/") + this->tileSets[i].source));
    }
}

TileLayer::~TileLayer() {}

void TileLayer::update()
{
}

void TileLayer::draw(const Vector2D &position)
{
    for (unsigned int i = 0; i < rowCount; i++)
    {
        for (unsigned int j = 0; j < columnCount; j++)
        {
            int tileID = tileMap[i][j];

            if (tileID == 0)
            {
                continue;
            }
            else
            {
                TileSet ts;
                for (unsigned int k = 0; k < tileSets.size(); k++)
                {
                    if (tileID >= tileSets[k].firstID && tileID <= tileSets[k].lastID)
                    {
                        ts = tileSets[k];
                        break;
                    }
                }

                int adjustedTileID = tileID - ts.firstID; // Ajusta o ID do tile dentro do tileset

                int tileRow = adjustedTileID / ts.columnCount;
                int tileColumn = adjustedTileID % ts.columnCount;

                // Ajusta a posição do desenho pela posição do mapa
                int drawX = j * ts.tileSize; // + position[0];
                int drawY = i * ts.tileSize; // + position[1];

                TextureManager::drawTile(textures[0], ts.tileSize, drawX, drawY, tileRow, tileColumn);
            }
        }
    }
}

int TileLayer::getTilesize()
{
    return tileSize;
}

TileMap TileLayer::getTileMap()
{
    return tileMap;
}

int TileLayer::getRowCount()
{
    return rowCount;
}

int TileLayer::getColCount()
{
    return columnCount;
}

TileSetList TileLayer::getTileSetList()
{
    return tileSets;
}