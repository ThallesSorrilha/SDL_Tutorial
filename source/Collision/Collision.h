#pragma once

#include "../Dimension/Dimension.h"
#include <vector>

class Collision
{
private:
    std::vector<std::vector<int>> layerTileMap;

public:
    Collision();
    ~Collision();

    bool checkCollision(const Dimension &box1, const Dimension &box2);
    bool mapCollision(const Dimension &box1);
};