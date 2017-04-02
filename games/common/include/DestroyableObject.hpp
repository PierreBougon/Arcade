//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_DESTROYABLEOBJECT_HPP
#define CPP_ARCADE_DESTROYABLEOBJECT_HPP

#include "LifelessEntity.hpp"

namespace arcade
{
    class DestroyableObject : public LifelessEntity
    {
    private:
        size_t hp;

    public:
        DestroyableObject(Entity const& cpy, size_t Hp);

        // With Sprite
        DestroyableObject(Vector2i pos,
                          size_t idSprite,
                          size_t spriteCount,
                          TileType Type,
                          TileTypeEvolution TypeEvolution,
                          Color col,
                          size_t Hp);

        // Without Sprite
        DestroyableObject(Vector2i pos,
                          TileType Type,
                          TileTypeEvolution TypeEvolution,
                          Color col,
                          size_t Hp);
        virtual ~DestroyableObject() {}

        bool isDestroy() const;
        size_t getHp() const;
        void takeDamage(size_t dam);
    };
}


#endif //CPP_ARCADE_DESTROYABLEOBJECT_HPP