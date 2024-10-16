#include <SDL.h>

#include "Timer.h"

void Timer::init()
{
    frameStart = SDL_GetTicks();
}

void Timer::update()
{
    frameStart = SDL_GetTicks();
}

Uint32 Timer::getGlobal()
{
    return frameStart;
}

Uint32 Timer::getNewTime()
{
    return SDL_GetTicks();
}