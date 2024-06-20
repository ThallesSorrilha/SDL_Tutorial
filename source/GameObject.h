#pragma once

#include <SDL.h>

#include "Vector2D.h"
#include "Animation.h"
#include "GOLoader.h"
#include "Physics.h"

class GameObject
{
protected:
    Vector2D position;
    Vector2D force;

    Physics physics;
    Animation animation;

    // colocar em class Animation
    bool moving;

public:
    GameObject(const GOLoader loader);
    ~GameObject();

    virtual void update();
    virtual void draw();
};