//
// Created by Pierre Bougon on 05/04/17.
//

#include "SoundRender.hpp"

arcade::SoundRender::SoundRender(unsigned int id, arcade::SoundAction mode, float volume, SoundType type)
        : Sound(id, mode, volume), type(type)
{
}

void arcade::SoundRender::loadFromFile(const std::string &file)
{
    //TODO error handling
    if (type == MUSIC)
    {
        if (!music.openFromFile(file))
            throw std::bad_alloc();
    }
    else
    {
        if (!soundBuffer.loadFromFile(file))
            throw std::bad_alloc();
        sound.setBuffer(soundBuffer);
    }
}

void arcade::SoundRender::play()
{
    if (type == MUSIC)
    {
        music.play();
    }
    else
    {
        sound.play();
    }
}
