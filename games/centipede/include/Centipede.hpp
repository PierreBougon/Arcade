//
// Created by brout_m on 04/04/17.
//

#ifndef CPP_ARCADE_CENTIPEDE_HPP
# define CPP_ARCADE_CENTIPEDE_HPP

# include <list>
# include "ALivingEntity.hpp"
# include "Bullet.hpp"
# include "Mushroom.hpp"

namespace arcade
{
    class CentipedePart : public ALivingEntity
    {
    public:
        CentipedePart(Vector2s const& pos);
        void setNb(size_t nb);
        void move();
        void action();
        void updatePlayerInput(std::vector<Event> &events);
        size_t getNb() const;

    private:
        size_t _nb;
    };

    class Centipede
    {
    public:
        enum CentipedeDirection
        {
            EAST,
            WEST,
            SOUTH,
            NORTH
        };
    public:
        Centipede(Vector2s const& pos,
                  size_t length = 10,
                  CentipedeDirection dirH = WEST,
                  CentipedeDirection dirV = SOUTH);
        Centipede(Vector2s const& pos,
                  std::list<CentipedePart> &&centipede,
                  CentipedeDirection dirH,
                  CentipedeDirection dirV);
        Centipede(Centipede const &centipede) = default;
        Centipede &operator=(Centipede const& centipede) = default;
        std::list<CentipedePart> &getBody();
        void setBody();
        void oneTurn(Bullet &bullet,
                     std::list<Centipede> &centipedes,
                     std::list<Mushroom> &mushrooms,
                     Map const& map);

    private:
        std::list<CentipedePart>    _body;
        size_t                      _poped;
        Vector2s                    _start;
        CentipedeDirection          _directionH;
        CentipedeDirection          _directionV;

        // private methods
        bool checkCentipedeCollision(std::list<Centipede> &centipedes, Vector2s const& pos);
        void testMove(Map const& map, Vector2s const& pos);
        void moveBody();
        void moveHead(std::list<Centipede> &centipedes,
                      std::list<Mushroom> &mushrooms,
                      Map const& map);
        bool hitByBullet(Bullet &bullet, std::list<Centipede> &centipedes, std::list<Mushroom> &mushrooms);
        std::list<CentipedePart> &&split(size_t pos, std::list<Mushroom> &mushroom);

        // deleted methods
        Centipede() = delete;
    };
}

#endif //CPP_ARCADE_CENTIPEDE_HPP
