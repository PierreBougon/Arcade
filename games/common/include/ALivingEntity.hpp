//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_ALIVINGENTITY_HPP
#define CPP_ARCADE_ALIVINGENTITY_HPP

#include "Entity.hpp"

namespace arcade
{
    enum Teams
    {
        NO_TEAM = -1,
        T_PLAYER,
        T_ENEMY,
        NB_TEAM
    };

    class ALivingEntity : public Entity
    {
    private:
        size_t hp;
        Teams team;

    public:
        ALivingEntity(Vector2i pos, size_t idSprite, size_t spriteCount, TileType Type, TileTypeEvolution TypeEvolution, Color col, size_t hp, Teams const& type);
        ALivingEntity(Vector2i pos, TileType Type, TileTypeEvolution TypeEvolution, Color col, size_t hp, Teams const& type);
        virtual ~ALivingEntity() {}

        bool isEnemy() const;
        bool isPlayer() const;
        size_t getHp() const;
        virtual void move() = 0;
        virtual void action() = 0;
    };
}


#endif //CPP_ARCADE_ALIVINGENTITY_HPP
