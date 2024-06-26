#pragma once

#include <SDL.h>

#include "Vector2D.h"
#include "Animation.h"
#include "GOLoader.h"
#include "Physics.h"
#include "Dimension.h"

class GameObject
{

public:
    Dimension dimension;
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