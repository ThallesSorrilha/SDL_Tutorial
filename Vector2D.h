#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>

class Vector2D
{

private:
    float x;
    float y;

public:
    inline Vector2D(float x, float y) : x(x), y(y) {}

    inline float getX() const { return this->x; }
    inline float getY() const { return this->y; }
    
    inline void setX(const float x) { this->x = x; }
    inline void setY(const float y) { this->y = y; }

    float length()
    {
        return std::sqrt(x * x + y * y);
    }

    Vector2D operator+(const Vector2D &v2) const
    {
        return Vector2D(this->x + v2.x, this->y + v2.y);
    }

    friend Vector2D &operator+=(Vector2D &v1, const Vector2D &v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }

    Vector2D operator*(float mult)
    {
        return Vector2D(this->x * mult, this->y * mult);
    }

    Vector2D &operator*=(float mult)
    {
        this->x *= mult;
        this->y *= mult;
        return *this;
    }

    Vector2D operator-(const Vector2D &v2) const
    {
        return Vector2D(this->x - v2.x, this->y - v2.y);
    }

    friend Vector2D &operator-=(Vector2D &v1, const Vector2D &v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }

    Vector2D operator/(float div)
    {
        return Vector2D(this->x / div, this->y / div);
    }

    Vector2D &operator/=(float div)
    {
        this->x /= div;
        this->y /= div;
        return *this;
    }

    void normalize()
    {
        float l = length();
        if (l > 0) // we never want to attempt to divide by 0
        {
            this->x *= 1 / l;
            this->y *= 1 / l;
        }
    }

};

#endif