//
// Created by brout_m on 03/04/17.
//

#ifndef CPP_ARCADE_CENTIPEDEKILLER_HPP
# define CPP_ARCADE_CENTIPEDEKILLER_HPP

# include "ALivingEntity.hpp"

namespace arcade
{
    class CentipedeKiller : public ALivingEntity
    {
    public:
        CentipedeKiller(Vector2i pos,
                        size_t idSprite,
                        size_t spriteCount,
                        TileType type,
                        TileTypeEvolution typeEvo,
                        Color col,
                        size_t hp);
        CentipedeKiller(Vector2i pos,
                        TileType type,
                        TileTypeEvolution typeEvolution,
                        Color col,
                        size_t hp);
    private:
    };
}

#endif //CPP_ARCADE_CENTIPEDEKILLER_HPP
