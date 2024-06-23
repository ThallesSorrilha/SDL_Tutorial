#pragma once

#include <SDL.h>

#include "GameObject.h"
#include "Vector2D.h"
#include "GOLoader.h"
#include "Control.h"

class Player : public GameObject
{

public:
    Control control;

    Player(const GOLoader loader, int controlMap[4]);
    void handleInput();
    void update() override;
    void draw() override;
};