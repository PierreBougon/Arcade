//
// Created by brout_m on 03/04/17.
//

#include "Vector2.hpp"
#include "Protocol.hpp"
#include "GameState.hpp"
#include "Color.hpp"
#include "CentipedeKiller.hpp"

arcade::CentipedeKiller::CentipedeKiller(Vector2ui pos,
                                         size_t idSprite,
                                         size_t spriteCount,
                                         TileType type,
                                         TileTypeEvolution typeEvo,
                                         Color col,
                                         size_t hp) :
    ALivingEntity(pos, idSprite, spriteCount, type, typeEvo, col, hp)

{

}

arcade::CentipedeKiller::CentipedeKiller(arcade::Vector2ui pos,
                                         arcade::TileType type,
                                         arcade::TileTypeEvolution typeEvolution,
                                         Color col,
                                         size_t hp) :
    ALivingEntity(pos, type, typeEvolution, col, hp)
{

}

void arcade::CentipedeKiller::action()
{

}

void arcade::CentipedeKiller::move(arcade::CentipedeKiller::MoveDirection dir) {

}
