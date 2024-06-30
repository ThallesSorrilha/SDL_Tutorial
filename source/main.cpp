#ifdef __MINGW32__
#define SDL_MAIN_HANDLED
#endif

#include <SDL.h>

#include "Definitions.h"
#include "Game.h"
#include "Timer.h"

int main(int argv, char **args)
{
    int frameTime;

    Game::init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, defaultWidthBlocks * defaultBlockSize, defaultHeightBlocks * defaultBlockSize, SDL_WINDOW_SHOWN); // 864x648

    while (Game::isRunning())
    {

        Timer::update();

        Game::handleEvents();
        Game::update();
        Game::draw();

        frameTime = Timer::getNewTime() - Timer::getGlobal();
        if (frameTime < defaultFrameDelay)
        {
            SDL_Delay(defaultFrameDelay - frameTime);
        }
    }

    Game::clean();
    return 0;
}