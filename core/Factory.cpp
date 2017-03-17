//
// Created by duhieu_b on 17/03/17.
//

#include "Factory.hpp"
#include "IComponent.hpp"
#include "Text.hpp"

std::unique_ptr<IComponent> arcade::Factory::createText()
{
    return new Text();
}

std::unique_ptr<IComponent> arcade::Factory::createButton()
{
    return nullptr;
}

std::unique_ptr<IComponent> arcade::Factory::createSlider()
{
    return nullptr;
}

std::unique_ptr<IComponent> arcade::Factory::createComponent(TypeComponent type)
{
    switch (type)
    {
        case TEXT:
            return createText();
        case BUTTON:
            return createButton();
        case SLIDER:
            return createSlider();
        default:
            return nullptr;
    }
}
