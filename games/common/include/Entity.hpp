//
// Created by duhieu_b on 01/04/17.
//

#ifndef CPP_ARCADE_ENTITY_HPP
#define CPP_ARCADE_ENTITY_HPP

#include <Protocol.hpp>
#include <GameState.hpp>
#include <Color.hpp>
#include "Vector2.hpp"
#include "Sprite.hpp"

namespace arcade
{
    class Entity
    {
    private:
        Vector2i abs;
        Vector2d shift;
        Vector2i prev;
        Sprite sprite;
        TileType type;
        TileTypeEvolution typeEvolution;
        Color color;
        Entity();
    public:
        Entity(Entity const& cpy);
        Entity(Vector2i const& pos, size_t id, size_t spriteCount, TileType Type, TileTypeEvolution TypeEvolution, Color col);

        virtual ~Entity() {}

        const Vector2i &getAbs() const;

        void setAbs(const Vector2i &abs);

        void setShift(const Vector2d &shift);

        void setPrev(const Vector2i &prev);

        const Vector2d &getShift() const;
        const Vector2i &getPrev() const;
        size_t advance();
        size_t getSpriteId() const;

        TileType getType() const;

        TileTypeEvolution getTypeEvolution() const;

        const Color &getColor() const;

        size_t getSpriteCount() const;

        void setType(TileType type);

        void setTypeEvolution(TileTypeEvolution typeEvolution);

        void setColor(const Color &color);
    };
}


#endif //CPP_ARCADE_ENTITY_HPP