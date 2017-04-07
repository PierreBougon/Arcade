//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_ALIVINGENTITY_HPP
# define CPP_ARCADE_ALIVINGENTITY_HPP

# include <vector>
# include "Event.hpp"
# include "Entity.hpp"

namespace arcade
{
    class ALivingEntity : public Entity
    {
    protected:
        size_t hp;

    public:
        ALivingEntity(Vector2s const &pos,
                      std::vector<size_t> idSprite,
                      std::vector<size_t> spriteCount,
                      Orientation dir,
                      TileType Type,
                      TileTypeEvolution TypeEvolution,
                      Color col,
                      size_t hp = 1,
                      bool collide = true);
        ALivingEntity(Vector2s const &pos,
                      TileType Type,
                      TileTypeEvolution TypeEvolution,
                      Color col,
                      size_t hp = 1,
                      bool collide = true);
        virtual ~ALivingEntity() {}

        bool isEnemy() const;
        bool isPlayer() const;
        size_t getHp() const;
        virtual void move() = 0;
        virtual void action() = 0;
        virtual void updatePlayerInput(std::vector<Event> &events) = 0;
    };
}


#endif //CPP_ARCADE_ALIVINGENTITY_HPP
