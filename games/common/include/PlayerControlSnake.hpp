//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_PLAYERCONTROL_HPP
#define CPP_ARCADE_PLAYERCONTROL_HPP

#include "ALivingEntity.hpp"
#include "Snake.hpp"

namespace arcade
{
    class PlayerControlSnake : public ALivingEntity
    {
    private:
        PlayerInputs input;

    public:
        PlayerControlSnake(Vector2s pos,
        size_t idSprite,
                size_t spriteCount,
        TileType Type,
                TileTypeEvolution TypeEvolution,
        Color col,
                size_t hp);
        PlayerControlSnake(Vector2s pos,
        TileType Type,
                TileTypeEvolution TypeEvolution,
        Color col,
                size_t hp);
        void move();
        void action();
        //void updateInput();
        void createObject();
    };
}


#endif //CPP_ARCADE_PLAYERCONTROL_HPP
