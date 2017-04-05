//
// Created by Pierre Bougon on 05/04/17.
//

#ifndef CPP_ARCADE_SOUNDRENDER_HPP_
#define CPP_ARCADE_SOUNDRENDER_HPP_


#include <Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "SFML/Audio/Sound.hpp"

namespace arcade
{
    class SoundRender : public Sound
    {
    private:
        SoundType       type;

        /// SFML Sounds classes are used to manage our sounds
        sf::SoundBuffer soundBuffer;
        sf::Sound       sound;
        sf::Music       music;

    public:
        SoundRender(unsigned int id, SoundAction mode = SoundAction::UNIQUE,
                    float volume = 50.0f, SoundType type = SoundType::MUSIC);

        void loadFromFile(const std::string &file);

        void play();
    };
}


#endif // !CPP_ARCADE_SOUNDRENDER_HPP_
