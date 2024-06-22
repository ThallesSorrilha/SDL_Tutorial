#pragma once

#include <SDL.h>

#include "Vector2D.h"
#include "Animation.h"
#include "GOLoader.h"
#include "Physics.h"

class GameObject
{
protected:
    Physics physics;
    Animation animation;

    bool moving; // não faz mt sentido - pode transformar em função

public:
    GameObject(const GOLoader loader);
    ~GameObject();

    virtual void update();
    virtual void draw();
};