#pragma once

class Vector2D
{

public:
    float x;
    float y;

    Vector2D(const float x = 0, const float y = 0);

    float length() const;
    void normalize(const int limit = 0);

    friend Vector2D operator+(const Vector2D &v1, const float num);
    friend Vector2D operator-(const Vector2D &v1, const float num);
    friend Vector2D operator*(const Vector2D &v1, const float num);
    friend Vector2D operator/(const Vector2D &v1, const float num);

    friend Vector2D operator+(const Vector2D &v1, const Vector2D &v2);
    friend Vector2D operator-(const Vector2D &v1, const Vector2D &v2);
    friend Vector2D operator*(const Vector2D &v1, const Vector2D &v2);
    friend Vector2D operator/(const Vector2D &v1, const Vector2D &v2);
    void operator=(const Vector2D &v1);

    friend void operator+=(Vector2D &v1, const Vector2D &v2);
    friend void operator-=(Vector2D &v1, const Vector2D &v2);
    friend void operator*=(Vector2D &v1, const Vector2D &v2);
    friend void operator/=(Vector2D &v1, const Vector2D &v2);
};