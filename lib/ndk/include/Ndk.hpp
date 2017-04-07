//
// Created by duhieu_b on 15/03/17.
//

#ifndef CPP_ARCADE_NDK_HPP
#define CPP_ARCADE_NDK_HPP

#include <curses.h>
#include "IGfxLib.hpp"
#include <map>

namespace arcade
{
    class Ndk : public arcade::IGfxLib
    {
    private:
        std::map<char, arcade::KeyboardKey> keyboard;
        WINDOW *win;
        bool pass;
        std::vector<std::string> vecString;
        size_t width;
        size_t height;
    public:
        Ndk();

        void soundControl(const Sound &sound);

        void loadSprites(std::vector<std::unique_ptr<ISprite>> &&sprites);

        void updateGUI(IGUI &gui);

        ~Ndk();
        bool pollEvent(arcade::Event &e);
        bool doesSupportSound() const;
        void loadSounds(std::vector<std::string> const &sounds);
        void playSound(int soundId);
        void updateMap(arcade::IMap const &map);
        void setSize(size_t Height, size_t Width);
        void setPosition(size_t y, size_t x);
        void initializeWindow();
        void display();
        void clear();

        void loadSounds(std::vector<std::pair<std::string, SoundType> > const &sounds) override;
    };
}

extern "C" arcade::IGfxLib *getLib();

#endif //CPP_ARCADE_NDK_HPP
