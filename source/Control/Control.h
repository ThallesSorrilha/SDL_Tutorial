#pragma once

class Control
{
private:
    int controlMap[5];

public:
    bool up;
    bool down;
    bool left;
    bool right;
    bool attack;

    Control(int arr[5]);
    ~Control();
    void handleInput();
};