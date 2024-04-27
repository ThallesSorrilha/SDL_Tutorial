#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

class Vector2D
{
public:
    inline Vector2D(float x, float y) : x(x), y(y) {}
    inline  getX() const { return this->x; }
    inline  getY() const { return this->y; }
    inline void setX(const float x) { this->x = x; }
    inline void setY(const float y) { this->y = y; }

    float length() { return std::sqrt(x * x + y * y); }

private:
    float x;
    float y;
};

#endif