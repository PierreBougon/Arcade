//
// Created by Pierre Bougon on 05/04/17.
//

#ifndef CPP_ARCADE_SOUNDRENDER_HPP_
#define CPP_ARCADE_SOUNDRENDER_HPP_


#include "Sound.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
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

        //////////////////////////////////////////////////////////////////////////////
        ///
        /// Use this method to set your sound with your SoundRender attributes
        //////////////////////////////////////////////////////////////////////////////
        void refresh();


        //////////////////////////////////////////////////////////////////////////////
        ///
        /// _Prefer using_ the refresh(); method since it will set
        /// your sound with the attributes you chose
        /// Those methods only wrap SFML sound methods to be able
        /// to deal with sound or music in the same class
        //////////////////////////////////////////////////////////////////////////////
        void play();

        void stop();

        void setVolume();

        void setVolume(float volume);

        void loop();

    };
}


#endif // !CPP_ARCADE_SOUNDRENDER_HPP_
