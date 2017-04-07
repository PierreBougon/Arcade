//
// Created by duhieu_b on 02/04/17.
//

#include "DestroyableObject.hpp"

arcade::DestroyableObject::DestroyableObject(arcade::Vector2s const &pos,
                                             std::vector<size_t> idSprite,
                                             std::vector<size_t> spriteCount,
                                             Orientation dir,
                                             TileType Type,
                                             TileTypeEvolution typeEvolution,
                                             Color col,
                                             size_t Hp,
                                             bool collide) :
        LifelessEntity(pos, idSprite, spriteCount, dir, Type, typeEvolution, col, collide),
        hp(Hp)
{

}

arcade::DestroyableObject::DestroyableObject(arcade::Vector2s const &pos,
                                             arcade::TileType Type,
                                             arcade::TileTypeEvolution TypeEvolution,
                                             arcade::Color col,
                                             size_t Hp,
                                             bool collide) :
        LifelessEntity(pos, Type, TypeEvolution, col, collide),
        hp(Hp)
{

}


arcade::DestroyableObject::DestroyableObject(arcade::Entity const& cpy,
                                             size_t Hp) :
        LifelessEntity(cpy),
        hp(Hp)
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

arcade::DestroyableObject &arcade::DestroyableObject::operator=(arcade::DestroyableObject &&)
{
    return *this;
}
