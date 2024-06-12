#pragma once

#include <SDL.h>

class Control
{
private:
    SDL_Scancode controlMap[4];

public:
    bool up;
    bool down;
    bool left;
    bool right;

    Control(SDL_Scancode arr[4]);
    ~Control();
    void handleInput();
};