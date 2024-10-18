#include "Control.h"
#include "../InputHandler/InputHandler.h"

Control::Control(int arr[5])
{
    for (int i = 0; i < 5; i++)
    {
        controlMap[i] = arr[i];
    }
}

Control::~Control() {}

void Control::handleInput()
{
    up = InputHandler::isKeyDown(controlMap[0]);
    right = InputHandler::isKeyDown(controlMap[1]);
    down = InputHandler::isKeyDown(controlMap[2]);
    left = InputHandler::isKeyDown(controlMap[3]);
    attack = InputHandler::isKeyDown(controlMap[4]);
}