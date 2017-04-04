//
// Created by duhieu_b on 02/04/17.
//

#include "LifelessEntity.hpp"

arcade::LifelessEntity::LifelessEntity(Entity const& cpy) :
        Entity(cpy)
{
}

arcade::LifelessEntity::LifelessEntity(Vector2s const &pos,
                                       size_t count, size_t
                                       spriteCount,
                                       TileType Type,
                                       TileTypeEvolution TypeEvolution,
                                       Color col,
                                       bool collide) :
    Entity(pos, count, spriteCount, Type, TypeEvolution, col, collide)
{

}

arcade::LifelessEntity::LifelessEntity(arcade::Vector2s const &pos,
                                       arcade::TileType Type,
                                       arcade::TileTypeEvolution TypeEvolution,
                                       arcade::Color col,
                                       bool collide) :
    Entity(pos, Type, TypeEvolution, col, collide)
{

}

bool arcade::LifelessEntity::isCollidable() const
{
    return collidable;
}


