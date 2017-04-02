//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_AICONTROLLED_HPP
#define CPP_ARCADE_AICONTROLLED_HPP

#include "ALivingEntity.hpp"

namespace arcade
{
    class AIControlled : public ALivingEntity
    {
    private:
        AIAtion actions;
        AIMovement movement;

    public:
        void move();
        void action();
        void createObject();
    };
}


#endif //CPP_ARCADE_AICONTROLLED_HPP
