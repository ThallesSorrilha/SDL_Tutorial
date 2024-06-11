#pragma once

#include <SDL.h>

#include "Vector2D.h"
#include "Animation.h"
#include "GOLoader.h"

class GameObject
{
protected:
    Vector2D position;
    Animation animation;
    bool moving;

public:
    GameObject(const GOLoader loader);
    ~GameObject();

    virtual void update();
    virtual void draw();
};