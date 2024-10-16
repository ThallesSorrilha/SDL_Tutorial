#include "TileSource.h"
#include "../TextureManager/TextureManager.h"

TileSource::TileSource(LoadTS LoadTS)
{
    this->tileSrc = TextureManager::loadTexture("assets/sprites/" + LoadTS.tileSrc + ".png");

    this->lenX = LoadTS.lenX;
    this->lenY = LoadTS.lenY;
}

TileSource::~TileSource()
{
}