//
// Created by duhieu_b on 17/03/17.
//

#ifndef CPP_ARCADE_GUI_HPP
#define CPP_ARCADE_GUI_HPP

#include <iostream>
#include <map>
#include <bits/unique_ptr.h>
#include "Factory.hpp"
#include "IComponent.hpp"
#include "GameState.hpp"
#include "IGUI.hpp"

namespace arcade
{
    class Gui : public arcade::IGUI
    {
    private:
        std::vector<IComponent &> components;
    public:
        ~Gui();
        Gui();
        size_t size() const;

        IComponent &at(std::size_t n);
    };
}

#endif //CPP_ARCADE_GUI_HPP
