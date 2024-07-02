#pragma once

#include "../GameObject/GameObject.h"
#include "../Control/Control.h"

class Player : public GameObject
{

public:
    Control control;

    Player(const GOLoader loader, int controlMap[4]);
    void handleInput();
    void update() override;
    void draw() const override;
    void collisionResolution(const GameObject &other) override;
};