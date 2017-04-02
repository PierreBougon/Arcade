//
// Created by duhieu_b on 02/04/17.
//

#include "ALivingEntity.hpp"

arcade::ALivingEntity::ALivingEntity(arcade::Vector2i pos, size_t idSprite, size_t spriteCount, TileType Type, TileTypeEvolution TypeEvolution, Color col, size_t Hp, const arcade::Teams &type) :
        Entity(pos, idSprite, spriteCount, Type, TypeEvolution, col), hp(Hp), team(type)
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

