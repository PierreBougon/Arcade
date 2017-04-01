//
// Created by duhieu_b on 17/03/17.
//

#include "Factory.hpp"
#include "Gui.hpp"

arcade::Gui::~Gui()
{
}

void arcade::Gui::createComponent(const std::string &name, arcade::TypeComponent component)
{
    components[name] = arcade::Factory::createComponent(component);
}

const IComponent *arcade::Gui::operator[](std::string const &name) const
{
    return components[name].get();
}

const std::map<std::string, std::unique_ptr<IComponent>> &arcade::Gui::getComponents() const
{
    return components;
}
