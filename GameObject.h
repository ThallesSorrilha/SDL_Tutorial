#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

#include "LoaderParams.h"

class GameObject
{

protected:
    int xPosition;
    int yPosition;
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