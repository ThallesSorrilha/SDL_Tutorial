#pragma once

#include <SDL.h>

#include "Vector2D.h"
#include "Animation.h"
#include "GOLoader.h"
#include "Physics.h"

class GameObject
{

public:
    Physics physics;
    Animation animation;

    GameObject(const GOLoader loader);
    ~GameObject();

    virtual void update();
    virtual void draw() const;
};