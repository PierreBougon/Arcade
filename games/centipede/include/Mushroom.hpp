//
// Created by brout_m on 04/04/17.
//

#ifndef CPP_ARCADE_MUSHROOM_HPP
# define CPP_ARCADE_MUSHROOM_HPP

# include "DestroyableObject.hpp"
# include "Bullet.hpp"

namespace arcade
{
    class Mushroom : public DestroyableObject
    {
    public:
        Mushroom(Vector2s const& pos);
        void hit(Bullet &bullet);
    };
}

#endif //CPP_ARCADE_MUSHROOM_HPP
