#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject
{

protected:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    int width;
    int height;
    int columnFrame;
    int rowFrame;
    std::string textureID;

public:
    GameObject(const LoaderParams *params);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif