#pragma once

#include "../GameObject/GameObject.h"
#include "../Control/Control.h"
#include "../Timer/Timer.h"
#include "../Collision/Collision.h"

class Player : public GameObject
{

public:
    Control control;
    Timer timeAttack;
    Dimension attackBox;
    Animation attackSprite;

    Collision collision;

    Player(const GOLoader loader, int controlMap[5], const GOLoader loader2);
    void handleInput();
    void update() override;
    void draw() const override;
    void collisionResolution(const GameObject &other) override;
    void initAttack();
    bool manageAttack();
    void positionAttackBox();
    void attackCollision(GameObject &other);
    void clean() override;
};