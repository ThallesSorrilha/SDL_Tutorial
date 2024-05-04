#include "InputHandler.h"
#include "Game.h"

void InputHandler::update()
{
    this->keyStates = SDL_GetKeyboardState(0);

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            TheGame::Instance()->quit();
        }
    }
}

void InputHandler::clean()
{
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (this->keyStates != nullptr)
    {
        if (keyStates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}