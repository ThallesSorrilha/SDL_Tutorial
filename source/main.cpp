#ifdef __MINGW32__
#define SDL_MAIN_HANDLED
#endif

#include <SDL.h>

#include "Definitions.h"
#include "Game.h"

int main(int argv, char **args)
{

    Uint32 frameStart;
    int frameTime;

    Game::init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (defaultWidthBlocks * defaultBlockSize), defaultHeightBlocks * defaultBlockSize, SDL_WINDOW_SHOWN); // 864x648

    while (Game::isRunning())
    {

        frameStart = SDL_GetTicks();

        Game::handleEvents();
        Game::update();
        Game::draw();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < defaultFrameDelay)
        {
            SDL_Delay(defaultFrameDelay - frameTime);
        }
    }

    Game::clean();
    return 0;
}