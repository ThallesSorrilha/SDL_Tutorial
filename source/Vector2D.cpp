#include <math.h>

#include "Vector2D.h"

Vector2D::Vector2D(const float x, const float y)
{
    this->x = x;
    this->y = y;
}

float Vector2D::length() const
{
    return std::sqrt(this->x * this->x + this->y * this->y);
}

void Vector2D::normalize(const int limit)
{
    float l = Vector2D::length();
    if (l > limit)
    {
        this->x *= 1 / l;
        this->y *= 1 / l;
    }
}

Vector2D operator+(const Vector2D &v1, const Vector2D &v2)
{
    return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

Vector2D operator-(const Vector2D &v1, const Vector2D &v2)
{
    return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

Vector2D operator*(const Vector2D &v1, const Vector2D &v2)
{
    return Vector2D(v1.x * v2.x, v1.y * v2.y);
}

Vector2D operator/(const Vector2D &v1, const Vector2D &v2)
{
    return Vector2D(v1.x / v2.x, v1.y / v2.y);
}

void operator+=(Vector2D &v1, const Vector2D &v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
}

void operator-=(Vector2D &v1, const Vector2D &v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
}

void operator*=(Vector2D &v1, const Vector2D &v2)
{
    v1.x *= v2.x;
    v1.y *= v2.y;
}

void operator/=(Vector2D &v1, const Vector2D &v2)
{
    v1.x /= v2.x;
    v1.y /= v2.y;
}