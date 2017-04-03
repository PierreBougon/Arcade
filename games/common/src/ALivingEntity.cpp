//
// Created by duhieu_b on 02/04/17.
//

#include "ALivingEntity.hpp"

arcade::ALivingEntity::ALivingEntity(arcade::Vector2s pos,
                                     size_t idSprite,
                                     size_t spriteCount,
                                     TileType Type,
                                     TileTypeEvolution TypeEvolution,
                                     Color col,
                                     size_t Hp,
                                     bool collide) :
        Entity(pos, idSprite, spriteCount, Type, TypeEvolution, col, collide),
        hp(Hp)
{
}

arcade::ALivingEntity::ALivingEntity(arcade::Vector2s pos,
                                     arcade::TileType Type,
                                     arcade::TileTypeEvolution TypeEvolution,
                                     arcade::Color col,
                                     size_t Hp,
                                     bool collide) :
    Entity(pos, Type, TypeEvolution, col, collide),
    hp(Hp)
{

}

bool arcade::ALivingEntity::isEnemy() const
{
    return (getTypeEvolution() == TileTypeEvolution::ENEMY);
}

bool arcade::ALivingEntity::isPlayer() const
{
    return (getTypeEvolution() == TileTypeEvolution::PLAYER);
}

size_t arcade::ALivingEntity::getHp() const
{
    return hp;
}