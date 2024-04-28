#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>

class InputHandler
{

private:
    static InputHandler *instance;
    InputHandler(){};
    ~InputHandler() {}

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
};

typedef InputHandler TheInputHandler;

#endif