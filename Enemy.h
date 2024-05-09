#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>

#include "LoaderParams.h"
#include "GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(const LoaderParams& params);
    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;
};

#endif