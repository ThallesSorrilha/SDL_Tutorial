#pragma once

#include <vector>

#include <SDL.h>

#include "GameObject.h"
#include "Map.h"

class Game
{

private:
    static bool run;
    static SDL_Window *window;

public:
    static SDL_Renderer *renderer;
    static std::vector<GameObject *> gameObjects;
    static Map *map;

    static void init(const char *title, const int xPosition, const int yPosition, const int width, const int height, const int flags);
    static void handleEvents();
    static void update();
    static void draw();
    static void clean();

    static bool isRunning();
    static void quit();
};