//
// Created by duhieu_b on 17/03/17.
//

#include "Factory.hpp"
#include "Gui.hpp"

arcade::Gui::~Gui()
{
}

size_t arcade::Gui::size() const
{
    return components.size();
}

arcade::IComponent &arcade::Gui::at(std::size_t n)
{
    size_t counter(0);

    for (std::vector<IComponent &>::iterator it = components.begin(); it != components.end() ; ++it)
    {
        if (counter == n)
            return (*it);
        counter++;
    }
}

arcade::Gui::Gui()
{
}
