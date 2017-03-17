//
// Created by duhieu_b on 15/03/17.
//

#ifndef CPP_ARCADE_NDK_HPP
#define CPP_ARCADE_NDK_HPP

#include <curses.h>
#include <IGfxLib.hpp>
#include <map>

namespace arcade
{
    class Ndk : public arcade::IGfxLib
    {
    private:
        std::map<char, arcade::KeyboardKey> keyboard;
        WINDOW *win;
        bool pass;

    public:
        Ndk();
        ~Ndk();
        bool pollEvent(arcade::Event &e);
        bool doesSupportSound() const = delete;
        void loadSounds(std::vector<std::string> const &sounds) = delete;
        void playSound(int soundId) = delete;
        void updateMap(arcade::IMap const &map);
        void updateGUI(arcade::IGUI const &gui);
        void setSize(size_t height, size_t width) = delete;
        void setPosition(size_t y, size_t x) = delete;
        void initializeWindow() = delete;
        void display();
        void clear();
    };
}

#endif //CPP_ARCADE_NDK_HPP
