#pragma once

#include <SDL.h>

#include "../Vector2D/Vector2D.h"
#include "../Animation/Animation.h"
#include "../GOLoader/GOLoader.h"
#include "../Physics/Physics.h"
#include "../Dimension/Dimension.h"

enum class Type
{
    Player,
    Enemy,
    GameObject
};

class GameObject
{

public:
    Type type;

    // vetor de hit box
    Dimension dimension;
    Physics physics;
    Vector2D direction;
    Animation animation;

    int atack;
    int life;
    int maxLife;

    GameObject(const GOLoader loader);
    ~GameObject();

    virtual void update();
    virtual void draw() const;
    virtual void clean();
    virtual void collisionResolution(const GameObject &other);
    virtual void sufferDamage();
    virtual bool isDead();

    bool isDirect() const;
};