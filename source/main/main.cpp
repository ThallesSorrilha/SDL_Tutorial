#ifdef __MINGW32__
#define SDL_MAIN_HANDLED
#endif

#include <SDL.h>

#include "../Definitions/Definitions.h"
#include "../Game/Game.h"
#include "../Timer/Timer.h"

#include <iostream>

int main(int argv, char **args)
{
    int frameTime;

    Game::init("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, defaultWidthBlocks * defaultBlockSize, defaultHeightBlocks * defaultBlockSize, SDL_WINDOW_ALWAYS_ON_TOP); // 864x648

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

    std::cout << "Vou limpar o jogo" << std::endl;
    Game::clean();
    return 0;
}