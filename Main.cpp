#ifdef __MINGW32__
#define SDL_MAIN_HANDLED
#endif

// g++ Main.cpp Game.cpp TextureManager.cpp SDLGameObject.cpp LoaderParams.cpp Player.cpp Enemy.cpp -o Main.exe `sdl2-config --cflags --libs` -lSDL2_image

#include "Main.h"

int main(int argc, char *args[])
{
    if (!TheGame::Instance()->init("My Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN))
    {
        TheGame::Instance()->clean();
        return 1;
    }

    while (TheGame::Instance()->getRun())
    {
        TheGame::Instance()->input();

        TheGame::Instance()->update();

        TheGame::Instance()->render();

        SDL_Delay(10);
    }

    TheGame::Instance()->clean();

    return 0;
}