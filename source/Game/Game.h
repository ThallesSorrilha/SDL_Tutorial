#pragma once

#include <vector>

#include <SDL.h>

#include "../GameObject/GameObject.h"
#include "../Map/Map.h"
#include "../Collision/Collision.h"

class Game
{

private:
    inline static bool run = false;
    inline static SDL_Window *window = nullptr; // interessante

public:
    inline static SDL_Renderer *renderer = nullptr;
    inline static std::vector<GameObject *> gameObjects;
    inline static Map *map = nullptr;
    inline static Collision *collision = nullptr;

    static void init(const char *title, const int xPosition, const int yPosition, const int width, const int height, const int flags);
    static void handleEvents();
    static void update();
    static void draw();
    static void clean();

    static bool isRunning();
    static void quit();
};