#include "Map.h"

#include "../TextureManager/TextureManager.h"
#include "../Definitions/Definitions.h"

Map::Map(const int arr[defaultHeightBlocks][defaultWidthBlocks], LoadTS loadts) : tileSource(loadts)
{
    load(arr);

    src.w = defaultSpriteUnit;
    src.h = defaultSpriteUnit;

    dest.w = defaultBlockSize;
    dest.h = defaultBlockSize;

    src.x = src.y = 0;
    dest.x = dest.y = 0;
}

Map::~Map() {}

void Map::load(const int arr[defaultHeightBlocks][defaultWidthBlocks])
{
    for (int row = 0; row < defaultHeightBlocks; row++)
    {
        for (int column = 0; column < defaultWidthBlocks; column++)
        {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::gif()
{
    int columnFrame = int(SDL_GetTicks() / 2000) % defaultGifSteps;
    src.x = columnFrame * defaultSpriteUnit;
}

void Map::update()
{
    // Map::gif();
}

void Map::draw()
{
    for (int row = 0; row < defaultHeightBlocks; row++)
    {
        for (int column = 0; column < defaultWidthBlocks; column++)
        {

            dest.x = column * defaultBlockSize;
            dest.y = row * defaultBlockSize;

            int type = map[row][column] - 1;
 
            src.y = (type / tileSource.lenX) * defaultSpriteUnit;
            src.x = (type % tileSource.lenX) * defaultSpriteUnit;

            TextureManager::draw(tileSource.tileSrc, src, dest);
        }
    }
}

void Map::clean() const
{
    SDL_DestroyTexture(tileSource.tileSrc);
}