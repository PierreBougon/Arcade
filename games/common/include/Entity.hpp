//
// Created by duhieu_b on 01/04/17.
//

#ifndef CPP_ARCADE_ENTITY_HPP
# define CPP_ARCADE_ENTITY_HPP

#include <vector>
# include "Protocol.hpp"
# include "GameState.hpp"
# include "Color.hpp"
# include "Vector2.hpp"
# include "Sprite.hpp"

namespace arcade
{
    enum Orientation
    {
        UP = 0,
        RIGHT,
        DOWN,
        LEFT
    };

    class Entity
    {
    protected:
        Vector2s abs;
        Vector2d shift;
        Vector2s prev;
        TileType type;
        TileTypeEvolution typeEvolution;
        Color color;
        bool spriteSet;
        bool collidable;
        Orientation curSprite;
        std::vector<Sprite> sprite;
        Entity() = delete;

    public:
        // Constructors / Destructor
        virtual ~Entity() {}
        Entity(Entity const& cpy);

        // Without Sprite
        Entity(Vector2s const& pos,
               TileType Type,
               TileTypeEvolution TypeEvolution,
               Color col,
               bool collide);

        // With Sprite
        Entity(Vector2s const& pos,
               std::vector<size_t> id,
               std::vector<size_t> spriteCount,
               Orientation dir,
               TileType Type,
               TileTypeEvolution TypeEvolution,
               Color col,
               bool collide);

        // Overload operator()
        Entity &operator=(Entity const& cpy);

        // Getters
        const Vector2s &getAbs() const;
        const Vector2d &getShift() const;
        const Vector2s &getPrev() const;
        bool hasSprite() const;
        size_t getSpriteId() const;
        TileType getType() const;
        TileTypeEvolution getTypeEvolution() const;
        const Color &getColor() const;
        size_t getSpriteCount() const;

        Orientation getOrientation() const;

        // Setters
        void setAbs(const Vector2s &abs);
        void setShift(const Vector2d &shift);
        void setPrev(const Vector2s &prev);
        void setType(TileType type);
        void setTypeEvolution(TileTypeEvolution typeEvolution);
        void setColor(const Color &color);
        void setSprite(std::vector<size_t> id, std::vector<size_t> spriteCount, size_t index = 0);
        void unSetSprite();
        void setNewDir(Orientation dir);

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