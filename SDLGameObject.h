#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include "GameObject.h"
#include "LoaderParams.h"

class SDLGameObject : public GameObject
{

protected:
    int xPosition;
    int yPosition;
    int width;
    int height;
    int columnFrame;
    int rowFrame;
    string textureID;

public:
    SDLGameObject(const LoaderParams *params);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif