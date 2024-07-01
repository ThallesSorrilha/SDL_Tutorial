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
    enum class Type
    {
        Player,
        Enemy
    };

    Type type;

    // vetor de hit box
    Dimension dimension;
    Physics physics;

    Vector2D direction;

    Animation animation;

    GameObject(const GOLoader loader);
    ~GameObject();

    virtual void update();
    virtual void draw() const;
    virtual void clean() const;
    virtual void collisionResolution(const GameObject &other);

    bool isDirect() const;
};