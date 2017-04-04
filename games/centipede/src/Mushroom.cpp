//
// Created by brout_m on 04/04/17.
//

#include "Mushroom.hpp"

arcade::Mushroom::Mushroom(Vector2s const& pos) :
        DestroyableObject(pos,
                          TileType::OBSTACLE,
                          TileTypeEvolution::OBSTACLE,
                          Color::Magenta,
                          4,
                          true)
{
}

void arcade::Mushroom::hit(arcade::Bullet &bullet) {
    if (bullet.getAbs() == abs)
    {
        --hp;
        bullet.hit();
    }
}