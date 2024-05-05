#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>

class InputHandler
{

private:
    static InputHandler *instance;
    InputHandler(){};
    ~InputHandler() {}
    const Uint8 *keyStates;
    SDL_Event event;

public:
    static InputHandler *Instance()
    {
        if (instance == nullptr)
        {
            instance = new InputHandler();
        }
        return instance;
    }

    void update();
    void clean();

    bool isKeyDown(SDL_Scancode key);
    void onKeyDown();
    void onKeyUp();
};

typedef InputHandler TheInputHandler;

#endif