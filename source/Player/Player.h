#pragma once

#include "../GameObject/GameObject.h"
#include "../Control/Control.h"
#include "../Timer/Timer.h"

class Player : public GameObject
{

public:
    Control control;

    bool isAttack;
    Timer timeAttack;

    Player(const GOLoader loader, int controlMap[5]);
    void handleInput();
    void update() override;
    void draw() const override;
    void collisionResolution(const GameObject &other) override;
    void attack() override;
    bool verifyAttack();
};