//
// Created by duhieu_b on 02/04/17.
//

#include "LifelessEntity.hpp"

arcade::LifelessEntity::LifelessEntity(Entity const& cpy, bool collide) :
        Entity(cpy),
        collidable(collide)
{
}

arcade::LifelessEntity::LifelessEntity(arcade::Vector2i pos,
                                       size_t count, size_t
                                       spriteCount,
                                       TileType Type,
                                       TileTypeEvolution TypeEvolution,
                                       Color col,
                                       size_t lay,
                                       bool collide) :
    Entity(pos, count, spriteCount, Type, TypeEvolution, col, lay),
    collidable(collide)
{

}

arcade::LifelessEntity::LifelessEntity(arcade::Vector2i pos,
                                       arcade::TileType Type,
                                       arcade::TileTypeEvolution TypeEvolution,
                                       arcade::Color col,
                                       size_t lay,
                                       bool collide) :
    Entity(pos, Type, TypeEvolution, col, lay),
    collidable(collide)
{

}

bool arcade::LifelessEntity::isCollidable() const
{
    return collidable;
}


