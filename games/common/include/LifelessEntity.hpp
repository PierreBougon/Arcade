//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_LIFELESSENTITY_HPP
# define CPP_ARCADE_LIFELESSENTITY_HPP

# include "Entity.hpp"

namespace arcade
{
    class LifelessEntity : public Entity
    {
    public:
        LifelessEntity(Entity const& cpy);
        // With Sprite
        LifelessEntity(Vector2s pos,
                       size_t count,
                       size_t spriteCount,
                       TileType Type,
                       TileTypeEvolution TypeEvolution,
                       Color col,
                       bool collide);
        // Without Sprite
        LifelessEntity(Vector2s pos,
                       TileType Type,
                       TileTypeEvolution TypeEvolution,
                       Color col,
                       bool collide);
        virtual ~LifelessEntity() {}

        bool isCollidable() const;
    };
}


#endif //CPP_ARCADE_LIFELESSENTITY_HPP
