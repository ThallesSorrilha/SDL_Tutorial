#include <iostream>
#include <string>

#include <SDL_image.h>

#include "../Game/Game.h"
#include "../InputHandler/InputHandler.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "../TextureManager/TextureManager.h"

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

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) // inicializa o áudio
    {
        std::cout << "Mix_OpenAudio error" << std::endl;
        return;
    }

    musica = Mix_LoadMUS("assets/sounds/musics/AdventureBegin.mp3");
    if (musica == nullptr)
    {
        std::cout << "AdventureBegin.mp3 error" << std::endl;
        return;
    }

    collision = Collision();

    map = new Map(level1, TileSource::level1);

    gameObjects.push_back(new Enemy(GOLoader{"assets/sprites/Enemy_72.png", 4, 4, 1, 1, 30, 1, 3}));
    gameObjects.push_back(new Enemy(GOLoader{"assets/sprites/Enemy_72.png", 6, 6, 1, 1, 30, 1, 3}));

    player = new Player(GOLoader{"assets/sprites/Player.png", 0, 0, 1, 1, 30, 1, 5}, control1, {"assets/sprites/Fire.png", 0, 0, 1, 1, 0, 0, 0});
    gameObjects.push_back(player);

    run = true;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 100);

    if (Mix_PlayMusic(musica, -1) == -1)
    {
        std::cout << "musica error" << std::endl;
        return;
    }
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
        if (!gameObjects[i]->isDead())
        {
            for (std::vector<GameObject *>::size_type j = i + 1; j < gameObjects.size(); j++)
            {
                if (collision.checkCollision(gameObjects[i]->dimension, gameObjects[j]->dimension))
                {
                    gameObjects[i]->collisionResolution(*gameObjects[j]);
                    gameObjects[j]->collisionResolution(*gameObjects[i]);
                }
            }
            gameObjects[i]->update();
            player->attackCollision(*gameObjects[i]);
        }
        else
        {
            if (!gameObjects[i]->isDestroyed)
            {
                gameObjects[i]->clean();
            }
        }
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
    std::cout << "Limpando o mapa" << std::endl;

    map->clean();

    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->clean();
    }

    Mix_FreeMusic(musica);
    Mix_CloseAudio();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    std::cout << "Quit" << std::endl;
    Mix_Quit();
    SDL_Quit();
};

bool Game::isRunning()
{
    return run;
};

void Game::quit()
{
    std::cout << "run = false" << std::endl;
    run = false;
}