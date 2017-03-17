//
// Created by Pierre Bougon on 17/03/17.
//

#include "SFMLCore.hpp"

arcade::SFMLCore::SFMLCore() : width(0), height(0), x(0), y(0)
{}

arcade::SFMLCore::~SFMLCore()
{}

bool arcade::SFMLCore::pollEvent(arcade::Event &e)
{
    //TODO: Poll event
    return false;
}

bool arcade::SFMLCore::doesSupportSound() const
{
    return true;
}

void arcade::SFMLCore::loadSounds(std::vector<std::string> const &sounds)
{
    std::unique_ptr<sf::Music> tmpSound;

    for (std::vector<std::string>::const_iterator it = sounds.begin(); it != sounds.end() ; ++it)
    {
        tmpSound = new sf::Music();
        if (!tmpSound->openFromFile(*it))
            throw std::bad_alloc();
        this->sounds.push_back(tmpSound);
    }
}

void arcade::SFMLCore::playSound(int soundId)
{
    if (sounds[soundId])
        sounds[soundId]->play();
}

void arcade::SFMLCore::setSize(size_t height, size_t width)
{
    this->height = static_cast<unsigned int>(height);
    this->width = static_cast<unsigned int>(width);
}

void arcade::SFMLCore::setPosition(size_t y, size_t x)
{
    this->x = x;
    this->y = y;
}

void arcade::SFMLCore::initializeWindow()
{
    sf::VideoMode videoMode(width, height);

    window = new sf::RenderWindow(videoMode, "Retro Furnace");
}

void arcade::SFMLCore::updateMap(const arcade::IMap &map)
{
    //TODO: update map
}

void arcade::SFMLCore::updateGUI(const arcade::IGUI &gui)
{
    //TODO: updateGUI
}

void arcade::SFMLCore::display()
{
    if (window)
        window->display();
}

void arcade::SFMLCore::clear()
{
    if (window)
        window->clear();
}
