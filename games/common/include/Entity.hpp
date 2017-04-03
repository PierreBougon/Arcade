//
// Created by duhieu_b on 01/04/17.
//

#ifndef CPP_ARCADE_ENTITY_HPP
# define CPP_ARCADE_ENTITY_HPP

# include <Protocol.hpp>
# include <GameState.hpp>
# include <Color.hpp>
# include "Vector2.hpp"
# include "Sprite.hpp"

namespace arcade
{
    class Entity
    {
    protected:
        Vector2ui abs;
        Vector2d shift;
        Vector2ui prev;
        TileType type;
        TileTypeEvolution typeEvolution;
        Color color;
        size_t layer;
        bool spriteSet;
        bool collidable;
        Sprite sprite;
        Entity() = delete;

    public:
        // Constructors / Destructor
        virtual ~Entity() {}
        Entity(Entity const& cpy);

        // Without Sprite
        Entity(Vector2ui const& pos,
               TileType Type,
               TileTypeEvolution TypeEvolution,
               Color col,
               bool collide);

        // With Sprite
        Entity(Vector2ui const& pos,
               size_t id,
               size_t spriteCount,
               TileType Type,
               TileTypeEvolution TypeEvolution,
               Color col,
               bool collide);

        // Getters
        const Vector2ui &getAbs() const;
        const Vector2d &getShift() const;
        const Vector2ui &getPrev() const;
        bool hasSprite() const;
        size_t getSpriteId() const;
        TileType getType() const;
        TileTypeEvolution getTypeEvolution() const;
        const Color &getColor() const;
        size_t getSpriteCount() const;

        // Setters
        void setAbs(const Vector2ui &abs);
        void setShift(const Vector2d &shift);
        void setPrev(const Vector2ui &prev);
        void setType(TileType type);
        void setTypeEvolution(TileTypeEvolution typeEvolution);
        void setColor(const Color &color);
        void setSprite(size_t id, size_t spriteCount = 1, size_t index = 0);
        void unSetSprite();

        // Special
        void pauseAnimation();
        void playAnimation();
        void resetAnimation();
        void setAnimationRepeat();
        void setAnimationUnique();
        void setAnimationMode(arcade::Sprite::SpriteMode mode);
        size_t advance();
    };
}

#endif //CPP_ARCADE_ENTITY_HPP