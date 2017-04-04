//
// Created by brout_m on 04/04/17.
//

#include "Vector2.hpp"
#include "Map.hpp"
#include "Bullet.hpp"

arcade::Bullet::Bullet(const Vector2s &pos) :
    LifelessEntity(pos, TileType::MY_SHOOT,
                   TileTypeEvolution::SHOT_PLAYER,
                   Color::Yellow,
                   false),
    alive(false)
{

}

void arcade::Bullet::reset(const arcade::Vector2s &pos)
{
    abs = pos;
    alive = true;
}

void arcade::Bullet::hit()
{
    alive = false;
}

bool arcade::Bullet::isAlive() const
{
    return alive;
}

void arcade::Bullet::go()
{
    if (abs.y > 0)
        abs.y--;
    else
        alive = false;
}
