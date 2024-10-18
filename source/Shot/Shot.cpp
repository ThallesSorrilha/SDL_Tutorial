#include "Shot.h"

Shot::Shot(const char *textureSheet, const float xPosition, const float yPosition, const float width, const float height, const int rowFrame)
    : animation(textureSheet, xPosition, yPosition, width, height, rowFrame)
{
    timer.scheduleEvent(0, 200);
}

Shot::~Shot() {}

void Shot::update()
{
    animation.update();
    if (!timer.isEventPresent())
    {
        this->clean();
    }
}

void Shot::draw()
{
    animation.draw();
}

void Shot::clean()
{
    animation.clean();
    timer.~Timer();
    this->~Shot();
}