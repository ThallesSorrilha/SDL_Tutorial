#include <iostream>

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Definitions.h"
#include "GOLoader.h"

GameObject::GameObject(const GOLoader loader) : animation(loader), position(loader.xPosition, loader.yPosition), force(0, 0), velocity(0, 0), acceleration(0, 0)
{
    moving = false;
    mass = loader.mass;
}

GameObject::~GameObject() {}

/*
*fazer somatório das forças (gravidade,...)
Força

aceleração = Força / massa

*atualizar posição
posição S = S0 + vel.temp + (ace.temp²)/2

*atualizar Velocidade
Vf = vel . temp
*/
void GameObject::physics()
{
    acceleration = force / mass;
}

void GameObject::update()
{
    GameObject::physics();

    if (!moving)
    {
        animation.columnFrame = 0;
    }
    animation.update(moving, position.x, position.y);
}

void GameObject::draw()
{
    animation.draw();
}