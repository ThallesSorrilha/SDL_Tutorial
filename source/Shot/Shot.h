#pragma once

#include <SDL.h>

#include "../Animation/Animation.h"
#include "../Timer/Timer.h"

class Shot
{

public:
    SDL_Rect location;
    Animation animation;
    Timer timer;

    Shot(const char *textureSheet, const float xPosition, const float yPosition, const float width, const float height, const int rowFrame);
    ~Shot();
    void update();
    void draw();
    void clean();
};
