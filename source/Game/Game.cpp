#include <iostream>

#include "../Game/Game.h"
#include "../InputHandler/InputHandler.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"

#include "../../assets/maps/level1.h"
#include "../../assets/controls/controls.h"

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

    collision = new Collision();
    map = new Map(level1);

    gameObjects.push_back(new Enemy(GOLoader{"assets/sprites/Enemy_72.png", 4, 4, 1, 1, 30}));
    gameObjects.push_back(new Enemy(GOLoader{"assets/sprites/Enemy_72.png", 6, 6, 1, 1, 30}));
    gameObjects.push_back(new Player(GOLoader{"assets/sprites/Player_72.png", 0, 0, 1, 1, 30}, control1));

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);
    run = true;
};

void Game::handleEvents()
{
    InputHandler::update();
};

void Game::update()
{
    map->update();

    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        for (std::vector<GameObject *>::size_type j = i + 1; j < gameObjects.size(); j++)
        {
            if (collision->checkCollision(gameObjects[i]->dimension, gameObjects[j]->dimension))
            {
                gameObjects[i]->collisionResolution(*gameObjects[j]);
                gameObjects[j]->collisionResolution(*gameObjects[i]);
            }
        }
        gameObjects[i]->update();
    }
};

void Game::draw()
{
    SDL_RenderClear(renderer);

    map->draw();
    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }

    SDL_RenderPresent(renderer);
};

void Game::clean()
{
    map->clean();
    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }

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