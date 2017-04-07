//
// Created by brout_m on 03/04/17.
//

#ifndef CPP_ARCADE_CENTIPEDEKILLER_HPP
# define CPP_ARCADE_CENTIPEDEKILLER_HPP

# include <memory>
# include <list>
# include "Map.hpp"
# include "ALivingEntity.hpp"
# include "Bullet.hpp"
# include "Mushroom.hpp"
# include "Centipede.hpp"

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
        typedef void (CentipedeKiller::*try_move_t)(const arcade::Map &map, const std::list<arcade::Mushroom*> &mushrooms);

    public:
        CentipedeKiller(Vector2s pos,
                        size_t idSprite,
                        size_t spriteCount,
                        TileType type,
                        TileTypeEvolution typeEvo,
                        Color col,
                        size_t hp);
        CentipedeKiller(Vector2s pos,
                        TileType type,
                        TileTypeEvolution typeEvolution,
                        Color col,
                        size_t hp);

        void action();
        void move();
        void move(const arcade::Map &map, const std::list<arcade::Mushroom*> &mushrooms);
        void updatePlayerInput(std::vector<Event> &events) override;
        void action(arcade::Bullet &bullet);
        bool touched(std::list<arcade::Centipede> &centipedes);

    private:
        KillerAction                    _action;
        KillerMove                      _move;

        bool isMoveTop(const Event& event) const;
        bool isMoveRight(const Event& event) const;
        bool isMoveLeft(const Event& event) const;
        bool isMoveDown(const Event& event) const;
        bool isFire(const Event& event) const;
        void tryMoveTop(const arcade::Map &map, const std::list<arcade::Mushroom*> &mushrooms);
        void tryMoveRight(const arcade::Map &map, const std::list<arcade::Mushroom*> &mushrooms);
        void tryMoveLeft(const arcade::Map &map, const std::list<arcade::Mushroom*> &mushrooms);
        void tryMoveBot(const arcade::Map &map, const std::list<arcade::Mushroom*> &mushrooms);
        void tryFire(arcade::Bullet &bullet);
    };
}

#endif //CPP_ARCADE_CENTIPEDEKILLER_HPP
