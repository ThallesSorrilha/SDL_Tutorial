#pragma once

#include <SDL.h>

class Control
{
private:
    int controlMap[4];

public:
    bool up;
    bool down;
    bool left;
    bool right;

    Control(int arr[4]);
    ~Control();
    void handleInput();
};