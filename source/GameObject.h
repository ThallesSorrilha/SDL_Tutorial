#pragma once

#include <SDL.h>

#include "Vector2D.h"
#include "Animation.h"
#include "GOLoader.h"
#include "Physics.h"

class GameObject
{

public:
    Vector2D position;
    Vector2D dimension;

    Vector2D direction;
    Physics physics;

    Animation animation;

    GameObject(const GOLoader loader);
    ~GameObject();

    virtual void update();
    virtual void draw() const;

    bool isDirect() const;
    void clean() const;
};