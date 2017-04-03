//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_LIFELESSENTITY_HPP
#define CPP_ARCADE_LIFELESSENTITY_HPP

#include "Entity.hpp"

namespace arcade
{
    class LifelessEntity : public Entity
    {
    private:
        bool collidable;

    public:
        LifelessEntity(Entity const& cpy, bool collide);
        // With Sprite
        LifelessEntity(Vector2ui pos,
                       size_t count,
                       size_t spriteCount,
                       TileType Type,
                       TileTypeEvolution TypeEvolution,
                       Color col,
                       bool collider);
        // Without Sprite
        LifelessEntity(Vector2ui pos,
                       TileType Type,
                       TileTypeEvolution TypeEvolution,
                       Color col,
                       bool collide);
        virtual ~LifelessEntity() {}

        bool isCollidable() const;
    };
}


#endif //CPP_ARCADE_LIFELESSENTITY_HPP
