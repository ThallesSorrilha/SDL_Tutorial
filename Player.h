#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

#include "LoaderParams.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
    Player(const LoaderParams *params);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif