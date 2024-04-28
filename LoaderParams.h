#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include <string>

class LoaderParams
{
private:
    int xPosition;
    int yPosition;
    int width;
    int height;
    std::string textureID;

public:
    LoaderParams(const int xPosition, const int yPosition, const int width, const int height, const std::string textureID)
    {
        this->xPosition = xPosition;
        this->yPosition = yPosition;
        this->width = width;
        this->height = height;
        this->textureID = textureID;
    }
    
    inline int getXPosition() const { return this->xPosition; }
    inline int getYPosition() const { return this->yPosition; }
    inline int getWidth() const { return this->width; }
    inline int getHeight() const { return this->height; }
    inline std::string getTextureID() const { return this->textureID; }
};

#endif