#pragma once

#include <SDL.h>

#include "GameObject.h"
#include "Vector2D.h"
#include "GOLoader.h"
#include "Control.h"

class Player : public GameObject
{
private:
    Vector2D direction;
    Control control;

public:
    Player(const GOLoader loader, int controlMap[4]);
    void handleInput();
    void update() override;
    void draw() override;
};