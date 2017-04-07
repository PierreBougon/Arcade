//
// Created by Pierre Bougon on 05/04/17.
//

#include "SoundManager.hpp"

arcade::SoundManager::SoundManager()
{}

void arcade::SoundManager::loadSounds(const std::vector<std::pair<std::string, arcade::SoundType>> &sounds)
{
    unsigned int id = 0;

    for (std::vector<std::pair<std::string, arcade::SoundType>>::const_iterator it = sounds.begin(); it < sounds.end(); ++it)
    {
        listSounds.push_back(std::make_unique<SoundRender>(id, SoundAction::UNIQUE, 50.0f, it->second));
        listSounds[id]->loadFromFile(it->first);
        ++id;
    }
}

void arcade::SoundManager::soundControl(const arcade::Sound &sound)
{
    switch (sound.mode)
    {
        case SoundAction::UNIQUE :
            listSounds[sound.id]->setLoop(false);
            break;
        case SoundAction::REPEAT :
            listSounds[sound.id]->setLoop(true);
            break;
        case SoundAction::PLAY :
            listSounds[sound.id]->play();
            break;
        case SoundAction::RESUME :
            listSounds[sound.id]->play();
            break;
        case SoundAction::PAUSE :
            listSounds[sound.id]->pause();
            break;
        case SoundAction::STOP :
            listSounds[sound.id]->stop();
            break;
        case SoundAction::VOLUME :
            listSounds[sound.id]->setVolume(sound.volume);
            break;
    }
}

arcade::SoundManager::~SoundManager()
{
}
