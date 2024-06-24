#pragma once

#include <SDL.h>

#include "GameObject.h"
#include "GOLoader.h"

class Enemy : public GameObject
{
public:
    Enemy(const GOLoader loader);
    virtual void update() override;
    virtual void draw() const override;
};