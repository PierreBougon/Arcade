//
// Created by brout_m on 16/03/17.
//

#include <exception>
#include "Lapin.hpp"

arcade::Lapin::Lapin() :
    Width(0),
    Height(0),
    X(0),
    Y(0),
    Window(nullptr),
    Map(nullptr)
{
    bunny_enable_full_blit(true);
}

arcade::Lapin::~Lapin()
{
    if (Window != nullptr)
        bunny_stop(Window);
    if (Map != nullptr)
        bunny_delete_clipable(&Map->clipable);
}

void arcade::Lapin::setSize(size_t height, size_t width)
{
    Height = static_cast<unsigned int>(height);
    Width = static_cast<unsigned int>(width);
}

void arcade::Lapin::setPosition(size_t y, size_t x)
{
    X = x;
    Y = y;
}

void arcade::Lapin::initializeWindow()
{
    Map = bunny_new_pixelarray(Width, Height);
    if (Map == nullptr)
        throw std::bad_alloc();
    Window = bunny_start(Width, Height, true, "Retro Furnace");
    if (Window == nullptr)
        throw std::bad_alloc();
    Contexts.push_back({0});
    Contexts.push_back({0});

    // TODO initialize contexts

    bunny_set_context(&Contexts[arcade::Lapin::MENU]);
}

bool arcade::Lapin::doesSupportSound() const
{
    return true;
}

void arcade::Lapin::display()
{
    bunny_blit(&Window->buffer, &Map->clipable, NULL);
    bunny_display(Window);
}

void arcade::Lapin::clear()
{
    bunny_clear(&Window->buffer, BLACK);
}

void arcade::Lapin::loadSounds(std::vector<std::string> const &sounds)
{
    for (size_t i = 0; i < sounds.size(); ++i)
    {
        if (isEffect(sounds[i])) {
            Effects[i] = bunny_load_effect(sounds[i].c_str();
            if (!Effects[i])
                throw std::bad_alloc();
            Where.push_back(true);
        } else {
            Musics[i] = bunny_load_music(sounds[i].c_str());
            if (!Musics[i])
                throw std::bad_alloc();
            bunny_sound_loop(&Musics[i]->sound, true);
            Where.push_back(false);
        }
        ++i;
    }
}

bool arcade::Lapin::isEffect(std::string const &file) const
{
    return file.compare(0, 6, "effect") == 0;
}

void arcade::Lapin::playSound(int soundId)
{
    if (soundId < Where.size())
    {
        if (Where[soundId])
        {
            bunny_sound_stop(&Effects[soundId]->sound);
            bunny_sound_play(&Effects[soundId]->sound);
        }
        else
        {
            bunny_sound_stop(&Musics[soundId]->sound);
            bunny_sound_play(&Musics[soundId]->sound);
        }
    }
}

bool arcade::Lapin::pollEvent(arcade::Event &e)
{
    // TODO pollEvents
    return false;
}

void arcade::Lapin::updateMap(const arcade::IMap &map)
{
    // TODO updateMap
}

void arcade::Lapin::updateGUI(const arcade::IGUI &gui)
{
    // TODO updateGUI
}
