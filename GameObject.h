#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject
{

// força e massa
// sem tamanho e posição dos Frames
// zerar força resultante, fazer processamento, somatório de forças e calcular a força resultante

// textura para um objeto precisa ter outra classe, para parâmetros da textura (tipo: Animation)
// modularizar

protected:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    int width;
    int height;
    int columnFrame;
    int rowFrame;
    SDL_Texture* textureID;

public:
    GameObject(const LoaderParams& params);
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif