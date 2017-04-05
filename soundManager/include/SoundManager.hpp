//
// Created by Pierre Bougon on 05/04/17.
//

#ifndef CPP_ARCADE_SOUNDMANAGER_HPP_
#define CPP_ARCADE_SOUNDMANAGER_HPP_


#include <string>
#include <vector>
#include <memory>
#include "Sound.hpp"
#include "SoundRender.hpp"

namespace arcade
{
    class SoundManager
    {
    private:
        std::vector<std::unique_ptr<SoundRender>>    listSounds;

    public:
        virtual ~SoundManager();

        void loadSounds(std::vector<std::pair<std::string, SoundType>> const &sounds);

        void soundControl(const Sound &sound);
    };
}


#endif // !CPP_ARCADE_SOUNDMANAGER_HPP_