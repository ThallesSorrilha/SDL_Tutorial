#include "InputHandler.h"
#include "Game.h"

InputHandler *InputHandler::instance = nullptr;

void InputHandler::update()
{
    this->keyStates = SDL_GetKeyboardState(0);

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                TheGame::Instance()->quit();
                break;

            case SDL_KEYDOWN:
                onKeyDown();
                break;

            case SDL_KEYUP:
                onKeyUp();
                break;

            default:
                break;
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

void InputHandler::onKeyDown()
{
    this->keyStates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
    this->keyStates = SDL_GetKeyboardState(0);
}