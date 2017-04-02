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
        LifelessEntity(Vector2i pos, size_t count, size_t spriteCount, TileType Type, TileTypeEvolution TypeEvolution, Color col, bool collider);
        virtual ~LifelessEntity() {}

        bool isCollidable() const;
    };
}


#endif //CPP_ARCADE_LIFELESSENTITY_HPP
