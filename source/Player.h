#pragma once

#include <SDL.h>

#include "GameObject.h"
#include "Vector2D.h"
#include "GOLoader.h"

class Player : public GameObject
{
private:
    Vector2D direction;

public:
    Player(const GOLoader loader);
    void handleInput();
    void update() override;
    void draw() override;
};