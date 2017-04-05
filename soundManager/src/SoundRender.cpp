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

void arcade::SoundRender::stop()
{
    if (type == MUSIC)
    {
        music.stop();
    }
    else
    {
        sound.stop();
    }
}

void arcade::SoundRender::setVolume()
{
    if (type == MUSIC)
    {
        music.setVolume(volume);
    }
    else
    {
        sound.setVolume(volume);
    }
}

void arcade::SoundRender::setVolume(float volume)
{
    if (type == MUSIC)
    {
        music.setVolume(volume);
    }
    else
    {
        sound.setVolume(volume);
    }
}

void arcade::SoundRender::loop()
{
    if (type == MUSIC)
    {
        music.setLoop(true);
    }
    else
    {
        sound.setLoop(true);
    }
}

void arcade::SoundRender::refresh()
{
    if (type == MUSIC)
    {
        music.setLoop(mode == REPEAT);
        music.setVolume(volume);
        SoundAction::
    }
    else
    {
        sound.setLoop(mode == REPEAT);
        sound.setVolume(volume);
    }
}
