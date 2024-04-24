#include "LoaderParams.h"

LoaderParams::LoaderParams(const int xPosition, const int yPosition, const int width, const int height, const string textureID)
{
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    this->width = width;
    this->height = height;
    this->textureID = textureID;
}

inline int LoaderParams::getXPosition() const { return xPosition; }

inline int LoaderParams::getYPosition() const { return yPosition; }

inline int LoaderParams::getWidth() const { return width; }

inline int LoaderParams::getHeight() const { return height; }

inline string LoaderParams::getTextureID() const { return textureID; }