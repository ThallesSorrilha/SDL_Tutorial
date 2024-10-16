#include "Collision.h"
#include "../Game/Game.h"

bool Collision::checkCollision(const Dimension &box1, const Dimension &box2)
{
    if ((box2.position.x + box2.size.x < box1.position.x))
    {
        return false;
    }

    if ((box1.position.x + box1.size.x < box2.position.x))
    {
        return false;
    }

    if ((box2.position.y + box2.size.y < box1.position.y))
    {
        return false;
    }

    if ((box1.position.y + box1.size.y < box2.position.y))
    {
        return false;
    }

    return true;
}

Collision::Collision()
{
    // erro, verificar ponteiro do TileLayer, getLayer, verificar 1 por 1 cada linha
    /*
    collisionLayer = (TileLayer *)Game::levelMap->getLayers().back();
    layerTileMap = collisionLayer->getTileMap();
    */
}

Collision::~Collision() {}

bool Collision::mapCollision(const Dimension &box1)
{
    // conferir quais quadrados do mapa o objeto está tocando
    // por meio da posição e dimensões
    // conferir se os quadrados do mapa são tangíveis ou não
    return false;
}