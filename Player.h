#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

#include "LoaderParams.h"
#include "GameObject.h"
#include "Vector2D.h"

class Player : public GameObject
{
private:
    Vector2D direction;
    void handleInput();

public:
    Player(const LoaderParams& params);
    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;
};

#endif