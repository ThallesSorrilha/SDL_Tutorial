#pragma once

#include <SDL.h>

class InputHandler
{

private:
    inline static const Uint8 *keyStates = nullptr;
    inline static SDL_Event event;

public:
    InputHandler() {}
    ~InputHandler() {}

    static void update();

    static bool isKeyDown(const SDL_Scancode key);
    static bool isKeyDown(const int key);
    static void onKeyDown();
    static void onKeyUp();
};