//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_PLAYERCONTROL_HPP
#define CPP_ARCADE_PLAYERCONTROL_HPP

#include "ALivingEntity.hpp"

namespace arcade
{
    class PlayerControlSnake : public ALivingEntity
    {
    public:
        enum PlayerInputs
        {
            I_NONE = -1,
            MOVE_UP,
            MOVE_DOWW,
            MOVE_RIGHT,
            MOVE_LEFT,
            NB_IMPUTS
        };

    private:
        PlayerInputs input;

    public:
        PlayerControlSnake(Vector2s pos,
        size_t idSprite,
                size_t spriteCount,
        TileType Type,
                TileTypeEvolution TypeEvolution,
        Color col, size_t hp, bool collide);
        PlayerControlSnake(Vector2s pos,
        TileType Type,
                TileTypeEvolution TypeEvolution,
        Color col,
                size_t hp, bool collide);
        void move();
        void action();

        void updatePlayerInput(std::vector<Event> &events);

        //void updateInput();
        void createObject();
    };
}


#endif //CPP_ARCADE_PLAYERCONTROL_HPP
