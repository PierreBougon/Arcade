//
// Created by duhieu_b on 02/04/17.
//

#include "ALivingEntity.hpp"

arcade::ALivingEntity::ALivingEntity(arcade::Vector2i pos,
                                     size_t idSprite,
                                     size_t spriteCount,
                                     TileType Type,
                                     TileTypeEvolution TypeEvolution,
                                     Color col,
                                     size_t Hp,
                                     arcade::Teams _type) :
        Entity(pos, idSprite, spriteCount, Type, TypeEvolution, col),
        hp(Hp),
        team(_type)
{
}

arcade::ALivingEntity::ALivingEntity(arcade::Vector2i pos,
                                     arcade::TileType Type,
                                     arcade::TileTypeEvolution TypeEvolution,
                                     arcade::Color col,
                                     size_t Hp,
                                     arcade::Teams _type) :
    Entity(pos, Type, TypeEvolution, col),
    hp(Hp),
    team(_type)
{

}

bool arcade::ALivingEntity::isEnemy() const
{
    return (team == T_ENEMY);
}

bool arcade::ALivingEntity::isPlayer() const
{
    return (team == T_PLAYER);
}

size_t arcade::ALivingEntity::getHp() const
{
    return hp;
}