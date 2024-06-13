#include "InputHandler.h"
#include "Game.h"

const Uint8 *InputHandler::keyStates = nullptr;
SDL_Event InputHandler::event;

void InputHandler::update()
{
    keyStates = SDL_GetKeyboardState(0);

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Game::quit();
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

bool InputHandler::isKeyDown(const SDL_Scancode key)
{
    if (keyStates != nullptr)
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

bool InputHandler::isKeyDown(const int key)
{
    if (keyStates != nullptr)
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
    keyStates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
    keyStates = SDL_GetKeyboardState(0);
}