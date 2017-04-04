//
// Created by duhieu_b on 17/03/17.
//

#ifndef CPP_ARCADE_FACTORY_HPP
#define CPP_ARCADE_FACTORY_HPP

#include <iostream>
#include <bits/unique_ptr.h>
#include "GameState.hpp"
#include "IComponent.hpp"

namespace arcade
{
    enum TypeComponent
    {
        COMP_NONE = -1,
        TEXT,
        BUTTON,
        SLIDER
    };

    class Factory
    {
        public:
            static std::unique_ptr<IComponent> createText();
            static std::unique_ptr<IComponent> createButton();
            static std::unique_ptr<IComponent> createSlider();
            static std::unique_ptr<IComponent> createComponent(arcade::TypeComponent type);
    };
}


#endif //CPP_ARCADE_FACTORY_HPP
