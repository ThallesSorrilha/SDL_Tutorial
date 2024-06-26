#include <SDL.h>

#include "Vector2D.h"
#include "Dimension.h"

class Collision
{
public:
    Collision();
    ~Collision();
    bool checkCollision(const Dimension &box1, const Dimension &box2);
};