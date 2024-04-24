#include "LoaderParams.h"

LoaderParams::LoaderParams(const int xPosition, const int yPosition, const int width, const int height, const string textureID)
{
    this->xPosition = xPosition;
    this->yPosition = yPosition;
    this->width = width;
    this->height = height;
    this->textureID = textureID;
}

int LoaderParams::getXPosition() const {
    return xPosition;
}

int LoaderParams::getYPosition() const {
    return yPosition;
}

int LoaderParams::getWidth() const {
    return width;
}

int LoaderParams::getHeight() const {
    return height;
}

string LoaderParams::getTextureID() const {
    return textureID;
}