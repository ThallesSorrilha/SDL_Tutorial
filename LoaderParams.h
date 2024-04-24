#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include "Utilities.h"

class LoaderParams
{
private:
    int xPosition;
    int yPosition;
    int width;
    int height;
    string textureID;

public:
    LoaderParams(const int xPosition, const int yPosition, const int width, const int height, const string textureID);
    int getXPosition() const;
    int getYPosition() const;
    int getWidth() const;
    int getHeight() const;
    string getTextureID() const;
};

#endif