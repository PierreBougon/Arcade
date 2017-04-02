//
// Created by duhieu_b on 02/04/17.
//

#include "DestroyableObject.hpp"

arcade::DestroyableObject::DestroyableObject(arcade::Vector2i pos,
                                             size_t idSprite,
                                             size_t spriteCount,
                                             TileType Type,
                                             TileTypeEvolution typeEvolution,
                                             Color col, size_t Hp) :
        LifelessEntity(pos, idSprite, spriteCount, Type, typeEvolution, col, true),
        hp(Hp)
{

}

arcade::DestroyableObject::DestroyableObject(arcade::Vector2i pos,
                                             arcade::TileType Type,
                                             arcade::TileTypeEvolution TypeEvolution,
                                             arcade::Color col,
                                             size_t Hp) :
        LifelessEntity(pos, Type, TypeEvolution, col, true),
        hp(Hp)
{

}


arcade::DestroyableObject::DestroyableObject(arcade::Entity const& cpy, size_t Hp) : LifelessEntity(cpy, true), hp(Hp)
{

}

bool arcade::DestroyableObject::isDestroy() const
{
    return (hp == 0);
}

size_t arcade::DestroyableObject::getHp() const
{
    return hp;
}

void arcade::DestroyableObject::takeDamage(size_t dam)
{
    if (dam > hp)
        hp = 0;
    else
        hp -= dam;
}