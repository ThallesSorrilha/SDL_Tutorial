#include "Player.h"
#include "../Definitions/Definitions.h"

#include "../Game/Game.h"

#include <iostream>

Player::Player(const GOLoader loader, int controlMap[5], const GOLoader loader2) : GameObject(loader), control(controlMap), timeAttack(), attackSprite(loader2), attackBox(loader)
{
    animation.gifFrameDelay = 200;
    type = Type::Player;
}

void Player::handleInput()
{
    control.handleInput();

    direction = 0;

    if (control.attack)
    {
        initAttack();
        return;
    }
    if (control.right)
    {
        direction.x += 1;
    }
    if (control.left)
    {
        direction.x -= 1;
    }
    if (control.up)
    {
        direction.y += 1;
    }
    if (control.down)
    {
        direction.y -= 1;
    }
}

void Player::update()
{
    handleInput();

    if (isAttack)
    {
        direction = 0;
    }

    physics.update(direction, 2);
    GameObject::update();

    bool moving = isDirect();
    if (!moving)
    {
        animation.columnFrame = 0;
    }
    else
    {
        animation.face(direction);
    }

    manageAttack();

    animation.update(moving, dimension.position, direction);
}

void Player::draw() const
{
    GameObject::draw();
    attackSprite.draw();
}

void Player::collisionResolution(const GameObject &other)
{
    if (other.type == Type::Enemy)
    {
        Vector2D impact = dimension.calculateInvasion(other.dimension);
        impact.normalize();
        impact /= 2;
        dimension.teleportRelative(impact);
        sufferDamage(other.attackPt);
    }
}

void Player::initAttack()
{
    isAttack = timeAttack.isEventPresent();
    if (!isAttack) // attack
    {
        timeAttack.scheduleEvent(0, 200);
        isAttack = true;
    }
}

bool Player::manageAttack()
{
    positionAttackBox();
    attackSprite.anchorSpriteInBox(attackBox);

    isAttack = timeAttack.isEventPresent();
    if (!isAttack)
    {
        attackSprite.rowFrame = 4;
    }
    else
    {
        animation.columnFrame = 4;
        direction = 0;
        attackSprite.rowFrame = animation.rowFrame;
    }

    attackSprite.update();

    return isAttack;
}

void Player::positionAttackBox()
{
    switch (animation.rowFrame)
    {
    case 0:
        attackBox.position.x = dimension.position.x;
        attackBox.position.y = dimension.position.y + 1;
        attackBox.size.x = 1;
        attackBox.size.y = 0.5;
        break;

    case 1:
        attackBox.position.x = dimension.position.x;
        attackBox.position.y = dimension.position.y - 1;
        attackBox.size.x = 1;
        attackBox.size.y = 0.5;
        break;

    case 2:
        attackBox.position.x = dimension.position.x - 1;
        attackBox.position.y = dimension.position.y;
        attackBox.size.x = 0.5;
        attackBox.size.y = 1;
        break;

    case 3:
        attackBox.position.x = dimension.position.x + 1;
        attackBox.position.y = dimension.position.y;
        attackBox.size.x = 0.5;
        attackBox.size.y = 1;
        break;

    default:
        break;
    }
}

void Player::attackCollision(GameObject &other)
{
    if (this->isAttack && other.type == Type::Enemy)
    {
        if (collision.checkCollision(this->attackBox, other.dimension))
        {
            Vector2D impact = other.dimension.calculateInvasion(this->attackBox);
            impact.normalize();
            impact /= 2;
            other.dimension.teleportRelative(impact);
            other.sufferDamage(this->attackPt);
        }
    }
}

void Player::clean()
{
    std::cout << "Limpando player" << std::endl;
    GameObject::clean();
    std::cout << "Vou dar quit no jogo" << std::endl;
    Game::quit();
}