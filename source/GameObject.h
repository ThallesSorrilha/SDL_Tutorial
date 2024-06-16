#pragma once

#include <SDL.h>

#include "Vector2D.h"
#include "Animation.h"
#include "GOLoader.h"

class GameObject
{
protected:
    Vector2D position;
    float mass;
    Vector2D force;
    Animation animation;

    // colocar em class Animation
    bool moving;

    // colocar em class Physics
    Vector2D velocity;
    Vector2D acceleration;


public:
    GameObject(const GOLoader loader);
    ~GameObject();

    void physics();
    virtual void update();
    virtual void draw();
};