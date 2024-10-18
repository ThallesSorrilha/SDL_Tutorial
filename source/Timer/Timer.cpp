#include <SDL.h>

#include "Timer.h"

#include <iostream>

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

Timer::Timer() {
    this->beginEvent = 0;
    this->endEvent = 0;
}

Timer::~Timer(){}

void Timer::scheduleEvent(Uint32 waitToBegin, Uint32 waitToEnd)
{
    beginEvent = Timer::getGlobal() + waitToBegin;
    endEvent = beginEvent + waitToEnd;
}

bool Timer::isEventPresent()
{
    Uint32 now = Timer::getNewTime();
    bool result = (beginEvent <= now && now < endEvent);
    return result;
}
