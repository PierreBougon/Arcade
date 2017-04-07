//
// Created by duhieu_b on 02/04/17.
//

#include <iostream>
#include "PlayerControlSnake.hpp"

void arcade::PlayerControlSnake::move()
{
    switch (input)
    {
        case MOVE_UP: prev = abs; abs.y--; break;
        case MOVE_DOWW: prev = abs; abs.y++; break;
        case MOVE_RIGHT: prev = abs; abs.x++; break;
        case MOVE_LEFT: prev = abs; abs.x--;  break;
        default: break;
    }
}

void arcade::PlayerControlSnake::action()
{

}

void arcade::PlayerControlSnake::createObject()
{
}

arcade::PlayerControlSnake::PlayerControlSnake(arcade::Vector2s pos, size_t idSprite, size_t spriteCount, arcade::TileType Type,
                                     arcade::TileTypeEvolution TypeEvolution, arcade::Color col, size_t hp, bool collide) :
        ALivingEntity(pos, idSprite, spriteCount, Type, TypeEvolution, col, hp, collide)
{
    input = MOVE_LEFT;
}

arcade::PlayerControlSnake::PlayerControlSnake(arcade::Vector2s pos, arcade::TileType Type,
                                     arcade::TileTypeEvolution TypeEvolution, arcade::Color col, size_t hp, bool collide) :
        ALivingEntity(pos, Type, TypeEvolution, col, hp, collide)
{
    input = MOVE_LEFT;
}

void arcade::PlayerControlSnake::updatePlayerInput(std::vector<arcade::Event> &events)
{
    for (std::vector<arcade::Event>::iterator it = events.begin(); it != events.end() ; ++it)
    {
        if ((*it).type == ET_KEYBOARD && (*it).action == AT_PRESSED)
        {
            switch ((*it).kb_key)
            {
                case KB_Z:
                case KB_ARROW_UP:
                    if (input != MOVE_DOWW)
                        input = MOVE_UP;
                    break;
                case KB_S:
                case KB_ARROW_DOWN:
                    if (input != MOVE_UP)
                        input = MOVE_DOWW;
                    break;
                case KB_D:
                case KB_ARROW_RIGHT:
                    if (input != MOVE_LEFT)
                        input = MOVE_RIGHT;
                    break;
                case KB_Q:
                case KB_ARROW_LEFT:
                    if (input != MOVE_RIGHT)
                        input = MOVE_LEFT;
                    break;
                default:
                    break;
            }
        }
    }
}
