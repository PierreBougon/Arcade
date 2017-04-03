//
// Created by duhieu_b on 02/04/17.
//

#include "PlayerControlSnake.hpp"

void arcade::PlayerControlSnake::move()
{

}

void arcade::PlayerControlSnake::action()
{

}

void arcade::PlayerControlSnake::createObject()
{
}

arcade::PlayerControlSnake::PlayerControlSnake(arcade::Vector2ui pos, size_t idSprite, size_t spriteCount, arcade::TileType Type,
                                     arcade::TileTypeEvolution TypeEvolution, arcade::Color col, size_t hp) :
        ALivingEntity(pos, idSprite, spriteCount, Type, TypeEvolution, col, hp)
{

}

arcade::PlayerControlSnake::PlayerControlSnake(arcade::Vector2ui pos, arcade::TileType Type,
                                     arcade::TileTypeEvolution TypeEvolution, arcade::Color col, size_t hp) :
        ALivingEntity(pos, Type, TypeEvolution, col, hp)
{

}
