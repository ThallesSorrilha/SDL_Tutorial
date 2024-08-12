
#include <iostream>

#include "GameMap.h"

GameMap::GameMap() {}

void GameMap::update()
{
    for (unsigned int i = 0; i < mapLayers.size(); i++)
    {
        mapLayers[i]->update();
    }
}

void GameMap::draw()
{
    for (unsigned int i = 0; i < mapLayers.size(); i++)
    {
        mapLayers[i]->draw(mapPosition);
    }
}

std::vector<Layer *> &GameMap::getLayers()
{
    return mapLayers;
}

void GameMap::setMapPosition(float x, float y)
{
    mapPosition = Vector2D(x, y);
}

Vector2D GameMap::getMapPosition()
{
    return mapPosition;
}

void GameMap::setMapDimension(float width, float height)
{
    mapDimension = Vector2D(width, height);
}

Vector2D GameMap::getMapDimension()
{
    return mapDimension;
}