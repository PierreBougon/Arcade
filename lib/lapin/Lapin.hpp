//
// Created by brout_m on 16/03/17.
//

#ifndef CPP_ARCADE_LAPIN_HPP
# define CPP_ARCADE_LAPIN_HPP

# include <IGfxLib.hpp>
# include <map>
# include <memory>
# include "lapin.h"
# include "Sound.hpp"

namespace arcade
{
    template <typename T>
    class Bunny_sound_deleter
    {
    public:
        void operator()(T* sound) {
            bunny_sound_stop(&sound->sound);
            bunny_delete_sound(&sound->sound);
        };
    };

    class Bunny_picture_deleter
    {
    public:
        void operator()(t_bunny_picture* picture);
    };


    class Lapin : IGfxLib
    {
    public:
        ~Lapin();
        Lapin();

    public:
        bool doesSupportSound() const;
        void clear();
        void loadSounds(std::vector<std::string> const &sounds);
        void soundControl(const Sound &sound);
        void loadSprites(std::vector<std::unique_ptr<ISprite>> &&sprites);
        bool pollEvent(Event &e);
        void updateGUI(IGUI &gui);
        void updateMap(IMap const &map);
        void display();

    private:
        Lapin(Lapin const &lapin) = delete;
        Lapin &operator=(Lapin const &lapin) = delete;
        void printOneSprite(t_bunny_position *pos, ITile const &tile);

    private:
        typedef std::map<size_t, std::unique_ptr<t_bunny_effect, Bunny_sound_deleter>>      t_bunny_map_effect;
        typedef t_bunny_context                                                             t_bunny_map_context;
        typedef std::map<char, arcade::KeyboardKey>                                         t_keyboard;
        typedef std::map<e_bunny_mouse_button , arcade::MouseKey >                          t_mouse;
        typedef std::unique_ptr<t_bunny_picture, Bunny_picture_deleter>                     t_sprite;
        typedef std::vector<std::vector<t_sprite>>                                          t_sprites;
        typedef unsigned int *t_uintcolormap;
        typedef t_color *t_colormap;

    private:
        unsigned int        Width;
        unsigned int        Height;
        unsigned int        TileWidth;
        unsigned int        TileHeight;
        size_t              X;
        size_t              Y;
        t_bunny_window      *Window;
        t_bunny_picture     *Map;
        t_bunny_map_context Context;
        t_keyboard          Keyboard;
        t_mouse             Mouse;
        t_bunny_map_effect  Effects;
        t_sprites           Sprites;
    };
}

#endif //CPP_ARCADE_LAPIN_HPP
