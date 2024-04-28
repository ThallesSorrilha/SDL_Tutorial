#ifndef GAME_H
#define GAME_H

#include <vector>

#include <SDL.h>

#include "GameObject.h"

class Game
{

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    bool run = false;

    std::vector<GameObject *> gameObjects;

    static Game *instance;
    Game();
    ~Game();

public:
    static Game *Instance()
    {
        if (instance == nullptr)
        {
            instance = new Game();
        }
        return instance;
    }

    /*
    Init SDL, create the main window and renderer
    xpos - in the user screen, SDL_WINDOWPOS_CENTERED to screen on center
    ypos - in the user screen, SDL_WINDOWPOS_CENTERED to screen on center
    width - of the window
    height - of the window
    flags - for the start window, SDL_WINDOW_SHOWN to show immediately the window
    */
    bool init(const char *title, const int xpos, const int ypos, const int width, const int height, const int flags);

    void input();
    void update();
    void render();
    void clean();

    bool getRun() const;
    SDL_Renderer *getRenderer() const;
};

typedef Game TheGame;

#endif