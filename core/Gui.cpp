//
// Created by duhieu_b on 17/03/17.
//

#include <Factory.hpp>
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

size_t arcade::Gui::size() const
{
    return components.size();
}

arcade::IComponent &arcade::Gui::at(std::size_t n)
{
    size_t counter(0);

    for (std::map<std::string, std::unique_ptr<IComponent>>::iterator it = components.begin(); it != components.end() ; ++it)
    {
        if (counter == n)
            return (*((*it).second.get()));
        counter++;
    }
}
