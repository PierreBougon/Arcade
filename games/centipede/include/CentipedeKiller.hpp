//
// Created by brout_m on 03/04/17.
//

#ifndef CPP_ARCADE_CENTIPEDEKILLER_HPP
# define CPP_ARCADE_CENTIPEDEKILLER_HPP

#include <Map.hpp>
# include "ALivingEntity.hpp"

namespace arcade
{
    class CentipedeKiller : public ALivingEntity
    {
    public:
        enum KillerMove
        {
            GO_UP = 0,
            GO_RIGHT,
            GO_DOWN,
            GO_LEFT,
            STAY
        };

        enum KillerAction
        {
            FIRE = 0,
            NOTHING
        };

        typedef bool (CentipedeKiller::*move_t)(const Event &event) const;
        typedef void (CentipedeKiller::*try_move_t)();

    public:
        CentipedeKiller(Vector2ui pos,
                        size_t idSprite,
                        size_t spriteCount,
                        TileType type,
                        TileTypeEvolution typeEvo,
                        Color col,
                        size_t hp,
                        const Map &map,
                        const std::vector<Entity> &entities);
        CentipedeKiller(Vector2ui pos,
                        TileType type,
                        TileTypeEvolution typeEvolution,
                        Color col,
                        size_t hp,
                        const Map &map,
                        const std::vector<Entity> &entities);
        void move();
        void action();
        void updatePlayerInput(const std::vector<Event> &events);


    private:
        KillerAction    _action;
        KillerMove      _move;
        const Map       &_map;
        const std::vector<Entity> &_entities;

        bool isMoveTop(const Event& event) const;
        bool isMoveRight(const Event& event) const;
        bool isMoveLeft(const Event& event) const;
        bool isMoveDown(const Event& event) const;
        bool isFire(const Event& event) const;
        void tryMoveTop();
        void tryMoveRight();
        void tryMoveLeft();
        void tryMoveBot();
    };
}

#endif //CPP_ARCADE_CENTIPEDEKILLER_HPP
