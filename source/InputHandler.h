#pragma once

#include <SDL.h>

class InputHandler
{

private:
    static const Uint8 *keyStates;
    static SDL_Event event;

public:
    InputHandler() {}
    ~InputHandler() {}

    static void update();

    static bool isKeyDown(SDL_Scancode key);
    static void onKeyDown();
    static void onKeyUp();
};