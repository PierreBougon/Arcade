//
// Created by brout_m on 16/03/17.
//

#ifndef CPP_ARCADE_LAPIN_HPP
# define CPP_ARCADE_LAPIN_HPP

# include <IGfxLib.hpp>
# include <map>
# include <memory>
# include "lapin.h"

namespace arcade
{
    template <typename T>
    class Bunny_sound_deleter
    {
    public:
        ~Bunny_sound_deleter(){};
        Bunny_sound_deleter(){};
        void operator()(T* sound)
        {
            bunny_sound_stop(&sound->sound);
            bunny_delete_sound(&sound->sound);
        };
    };

    class Lapin : IGfxLib
    {
    public:
        enum CONTEXT {
            MENU = 0,
            GAME,
        };

    public:
        ~Lapin();
        Lapin();

    public:
        void setSize(size_t height, size_t width);
        void setPosition(size_t y, size_t x);
        void initializeWindow();
        bool doesSupportSound() const;
        void clear();
        void loadSounds(std::vector<std::string> const &sounds);
        void playSound(int soundId);
        bool pollEvent(Event &e);
        void updateGUI(IGUI const &gui) override;
        void updateMap(IMap const &map) override;
        void display();

    private:
        Lapin(Lapin const &lapin) = delete;
        Lapin &operator=(Lapin const &lapin) = delete;
        bool isEffect(std::string const &file) const;
        typedef std::map<size_t, std::unique_ptr<t_bunny_effect, Bunny_sound_deleter>>   t_bunny_map_effect;
        typedef std::map<size_t, std::unique_ptr<t_bunny_music, Bunny_sound_deleter>>    t_bunny_map_music;
        typedef std::vector<t_bunny_context>                                             t_bunny_map_context;
        typedef std::map<char, arcade::KeyboardKey>                                      t_keyboard;

    private:
        unsigned int        Width;
        unsigned int        Height;
        size_t              X;
        size_t              Y;
        t_bunny_window      *Window;
        t_bunny_pixelarray  *Map;
        t_bunny_map_context Contexts;
        t_bunny_map_effect  Effects;
        t_bunny_map_music   Musics;
        std::vector<bool>   Where;
        t_keyboard          keyboard;
    };
}

#endif //CPP_ARCADE_LAPIN_HPP
