//
// Created by brout_m on 04/04/17.
//

#ifndef CPP_ARCADE_BULLET_HPP
# define CPP_ARCADE_BULLET_HPP

# include <list>
# include "Map.hpp"
# include "LifelessEntity.hpp"

namespace arcade
{
    class Bullet : public LifelessEntity
    {
    public:
        Bullet(Vector2s const &pos);
        void reset(Vector2s const &pos);
        void hit();
        bool isAlive() const;
        void go();

    private:
        bool alive;
    };
}

#endif //CPP_ARCADE_BULLET_HPP
