#include "Timer.h"

Timer::Timer()
{
    frameStart = SDL_GetTicks();
}

Timer::~Timer() {}

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