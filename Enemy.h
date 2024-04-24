#ifndef ENEMY_H
#define ENEMY_H

#include <SDL.h>

#include "LoaderParams.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
    Enemy(const LoaderParams *params);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif