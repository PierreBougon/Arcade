//
// Created by duhieu_b on 02/04/17.
//

#ifndef CPP_ARCADE_PLAYERCONTROL_HPP
#define CPP_ARCADE_PLAYERCONTROL_HPP

#include "ALivingEntity.hpp"

namespace arcade
{
    class PlayerControl : public ALivingEntity
    {
    private:
        PlayerInputs input;

    public:
        void move();
        void action();
        //void updateInput();
        void createObject();
    };
}


#endif //CPP_ARCADE_PLAYERCONTROL_HPP
