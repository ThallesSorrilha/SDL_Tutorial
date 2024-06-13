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

    static bool isKeyDown(const SDL_Scancode key);
    static bool isKeyDown(const int key);
    static void onKeyDown();
    static void onKeyUp();
};