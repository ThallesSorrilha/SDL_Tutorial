#ifdef __MINGW32__
#define SDL_MAIN_HANDLED
#endif

// g++ Main.cpp Game.cpp TextureManager.cpp GameObject.cpp Player.cpp Enemy.cpp -o Main.exe `sdl2-config --cflags --libs` -lSDL2_image

#include <SDL.h>

#include "Main.h"
#include "Game.h"

int main(int argc, char *args[])
{
    if (!TheGame::Instance()->init("My Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN))
    {
        TheGame::Instance()->clean();
        return 1;
    }

    while (TheGame::Instance()->getRun())
    {
        frameStart = SDL_GetTicks();

        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME)
        {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }

    TheGame::Instance()->clean();

    return 0;
}