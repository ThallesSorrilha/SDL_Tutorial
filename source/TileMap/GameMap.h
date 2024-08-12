#pragma once

#include <vector>
#include <iostream>

#include "TileLayer.h"
#include "../Vector2D/Vector2D.h"

class GameMap
{
private:
  std::vector<Layer *> mapLayers;
  Vector2D mapDimension;
  Vector2D mapPosition;
  int width = 0;
  int height = 0;

public:
  GameMap();
  void update();
  void draw();

  std::vector<Layer *> &getLayers();

  void setMapPosition(float x, float y);
  inline Vector2D getMapPosition();

  void setMapDimension(float width, float height);
  inline Vector2D getMapDimension();
};