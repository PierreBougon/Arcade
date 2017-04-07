//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_DESTROYABLEOBJECT_HPP
# define CPP_ARCADE_DESTROYABLEOBJECT_HPP

# include "LifelessEntity.hpp"

namespace arcade
{
    class DestroyableObject : public LifelessEntity
    {
    protected:
        size_t hp;

    public:
        DestroyableObject(Entity const& cpy, size_t Hp);
        DestroyableObject(DestroyableObject const &) = default;
        DestroyableObject(DestroyableObject &&) = default;
        DestroyableObject &operator=(DestroyableObject const &) = default;
        DestroyableObject &operator=(DestroyableObject &&);
        // With Sprite
        DestroyableObject(Vector2s const &pos,
                          std::vector<size_t> idSprite,
                          std::vector<size_t> spriteCount,
                          Orientation dir,
                          TileType Type = TileType::OTHER,
                          TileTypeEvolution TypeEvolution = TileTypeEvolution::FOOD,
                          Color col = Color::Red,
                          size_t Hp = 1,
                          bool collide = false);

        // Without Sprite
        DestroyableObject(Vector2s const &pos,
                          TileType Type = TileType::OTHER,
                          TileTypeEvolution TypeEvolution = TileTypeEvolution::FOOD,
                          Color col = Color::Red,
                          size_t Hp = 1,
                          bool collide = false);
        virtual ~DestroyableObject() {}

        bool isDestroy() const;
        size_t getHp() const;
        void takeDamage(size_t dam);
    };
}


#endif //CPP_ARCADE_DESTROYABLEOBJECT_HPP
