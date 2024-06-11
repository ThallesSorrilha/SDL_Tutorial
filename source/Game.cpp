#include <iostream>

#include "Game.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"
#include "GOLoader.h"
#include "Definitions.h"

#include "../assets/maps/level1.h"

SDL_Renderer *Game::renderer = nullptr;
bool Game::run = false;
std::vector<GameObject *> Game::gameObjects;
Map *Game::map = nullptr;
SDL_Window *Game::window = nullptr;

void Game::init(const char *title, int xPosition, int yPosition, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL error: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);
    if (window == nullptr)
    {
        std::cout << "window error" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        std::cout << "renderer error" << std::endl;
        return;
    }

    map = new Map(level1);
    gameObjects.push_back(new Enemy(GOLoader{"assets/Enemy_72.png", 0, 0, defaultBlockSize, defaultBlockSize}));
    gameObjects.push_back(new Player(GOLoader{"assets/Player_72.png", 100, 100, defaultBlockSize, defaultBlockSize}));

    run = true;
};

void Game::handleEvents()
{
    InputHandler::update();
};

void Game::update()
{
    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
};

void Game::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
    SDL_RenderClear(renderer);

    map->drawMap();
    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }

    SDL_RenderPresent(renderer);
};

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};

bool Game::isRunning()
{
    return run;
};

void Game::quit()
{
    run = false;
}