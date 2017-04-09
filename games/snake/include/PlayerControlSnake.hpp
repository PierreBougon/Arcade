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
                           std::vector<size_t> idSprite,
                           std::vector<size_t> spriteCount,
                           Orientation dir,
                           TileType Type = TileType::OTHER,
                           TileTypeEvolution TypeEvolution = TileTypeEvolution::PLAYER,
                           Color col = Color::Cyan, size_t hp = 1, bool collide = true);
        PlayerControlSnake(Vector2s pos,
                           TileType Type = TileType::OTHER,
                           TileTypeEvolution TypeEvolution = TileTypeEvolution::PLAYER,
                           Color col = Color::Cyan,
                           size_t hp = 1, bool collide = true);
        void move();
        void moveShift(double numTick, double maxTick);
        void action();

        void updatePlayerInput(std::vector<Event> &events);

        void updateSprite();
        void createObject();
    };
}


#endif //CPP_ARCADE_PLAYERCONTROL_HPP
