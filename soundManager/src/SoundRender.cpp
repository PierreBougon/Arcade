//
// Created by Pierre Bougon on 05/04/17.
//

#include <Logger.hpp>
#include "SoundRender.hpp"

arcade::SoundRender::SoundRender(unsigned int id, arcade::SoundAction mode, float volume, SoundType type)
        : Sound(id, mode, volume), type(type), error(false)
{
}

void arcade::SoundRender::loadFromFile(const std::string &file)
{
    //TODO error handling
    if (type == MUSIC)
    {
        if (!music.openFromFile(file))
        {
            Logger::log(Logger::Error, "Cannot open this sound file : " + file);
            error = true;
        }
    }
    else
    {
        if (!soundBuffer.loadFromFile(file))
        {
            Logger::log(Logger::Error, "Cannot open this sound file : " + file);
            error = true;
        }
        if (!error)
            sound.setBuffer(soundBuffer);
    }
}

void arcade::SoundRender::play()
{
    if (error)
        return;
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
    if (error)
        return;
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
    if (error)
        return;
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
    if (error)
        return;
    if (type == MUSIC)
    {
        music.setVolume(volume);
    }
    else
    {
        sound.setVolume(volume);
    }
}

void arcade::SoundRender::setLoop(bool state)
{
    if (error)
        return;
    if (type == MUSIC)
    {
        music.setLoop(state);
    }
    else
    {
        sound.setLoop(state);
    }
}

void arcade::SoundRender::refresh()
{
    if (error)
        return;
    if (type == MUSIC)
    {
        music.setLoop(mode == REPEAT);
        music.setVolume(volume);
    }
    else
    {
        sound.setLoop(mode == REPEAT);
        sound.setVolume(volume);
    }
}

void arcade::SoundRender::pause()
{
    if (type == MUSIC)
    {
        music.pause();
    }
    else
    {
        sound.pause();
    }
}

arcade::SoundRender::~SoundRender()
{
}
