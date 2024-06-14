#pragma once

#include <SDL.h>

#include "Vector2D.h"
#include "Animation.h"
#include "GOLoader.h"

class GameObject
{
protected:
    Vector2D position;
    /*Vector2D velocity;
    Vector2D acceleration;
    Vector2D force;*/
    Animation animation;
    bool moving;

public:
    GameObject(const GOLoader loader);
    ~GameObject();

    virtual void update();
    virtual void draw();
};