#include <iostream>

#include <SDL_image.h>

#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
#include "InputHandler.h"

Game *Game::instance = nullptr;

Game::Game() {}
Game::~Game() {}

bool Game::init(const char *title, const int xpos, const int ypos, const int width, const int height, const int flags)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        return criticalError("SDL_INIT_VIDEO error ");
    }

    if ((IMG_Init(IMG_INIT_PNG) == 0))
    {
        return criticalError("IMG_INIT_PNG error ");
    }

    this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (this->window == nullptr)
    {
        return criticalError("Main Window error ");
    };

    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    if (this->renderer == nullptr)
    {
        return criticalError("Main Renderer error ");
    };

    // some image loads
    if (!TheTextureManager::Instance()->loadTexture("assets/Player_72.png", "player", this->renderer))
    {
        return criticalError("Player img error");
    }

    if (!TheTextureManager::Instance()->loadTexture("assets/FlyEnemy_72.png", "enemy", this->renderer))
    {
        return criticalError("Fly Enemy img error");
    }

    this->gameObjects.push_back(new Player(new LoaderParams(100, 100, 72, 72, "player")));
    this->gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 72, 72, "enemy")));

    this->run = true;
    return this->run;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::update()
{
    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        this->gameObjects[i]->update();
    }
}

void Game::render()
{
    SDL_SetRenderDrawColor(this->renderer, 240, 240, 255, 255);
    SDL_RenderClear(this->renderer);

    for (std::vector<GameObject *>::size_type i = 0; i < gameObjects.size(); i++)
    {
        this->gameObjects[i]->draw();
    }

    SDL_RenderPresent(this->renderer);
}

void Game::clean()
{
    TheInputHandler::Instance()->clean();
    if (this->renderer != nullptr)
    {
        SDL_DestroyRenderer(this->renderer);
    }

    if (this->window != nullptr)
    {
        SDL_DestroyWindow(this->window);
    }

    if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
    {
        SDL_Quit();
    }
}

bool Game::getRun() const
{
    return this->run;
}

SDL_Renderer *Game::getRenderer() const
{
    return renderer;
}

bool Game::criticalError(std::string msg) const
{
    std::cerr << msg << std::endl;
    return false;
}