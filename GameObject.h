// SDLGameObject n precisa, deixar só GameObject
// usar biblioteca de vetores

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "LoaderParams.h"

class GameObject
{
protected:
    GameObject(const LoaderParams *params) {}
    virtual ~GameObject() {}

public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
};

#endif