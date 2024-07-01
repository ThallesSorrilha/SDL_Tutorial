#pragma once

#include <SDL.h>

#include "GameObject.h"
#include "GOLoader.h"

class Enemy : public GameObject
{
public:
    Uint32 strollTime = 0;
    float speed = 0.0F;

    Enemy(const GOLoader loader);
    virtual void update() override;
    virtual void draw() const override;
    virtual void randomStroll();
    virtual void collisionResolution(const GameObject &other) override;
};