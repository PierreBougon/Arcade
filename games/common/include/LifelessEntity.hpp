//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_LIFELESSENTITY_HPP
# define CPP_ARCADE_LIFELESSENTITY_HPP

#include <vector>
# include "Entity.hpp"

namespace arcade
{
    class LifelessEntity : public Entity
    {
    public:
        LifelessEntity(Entity const& cpy);
        // With Sprite
        LifelessEntity(Vector2s const &pos,
                       std::vector<size_t> count,
                       std::vector<size_t> spriteCount,
                       Orientation dir,
                       TileType Type,
                       TileTypeEvolution TypeEvolution,
                       Color col,
                       bool collide = false);
        // Without Sprite
        LifelessEntity(Vector2s const &pos,
                       TileType Type,
                       TileTypeEvolution TypeEvolution,
                       Color col,
                       bool collide = false);
        virtual ~LifelessEntity() {}

        bool isCollidable() const;
    };
}


#endif //CPP_ARCADE_LIFELESSENTITY_HPP
