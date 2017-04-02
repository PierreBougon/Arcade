//
// Created by duhieu_b on 01/04/17.
//

#ifndef CPP_ARCADE_ENTITY_HPP
#define CPP_ARCADE_ENTITY_HPP

# include "ISprite.hpp"
# include "Vector2.hpp"
# include "GameState.hpp"
# include "Protocol.hpp"

namespace arcade
{
    class Entity
    {
    private:
        Vector2i abs;
        Vector2d shift;
        Vector2i prev;
        ISprite sprite;

    public:
        Entity(Vector2i const& pos, size_t id, size_t spriteCount);
        virtual ~Entity() {}
        const Vector2i &getAbs() const;
        const Vector2d &getShift() const;
        const Vector2i &getPrev() const;
        size_t advance();
        size_t getSpriteId() const;
    };
}


#endif //CPP_ARCADE_ENTITY_HPP