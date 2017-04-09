//
// Created by brout_m on 16/03/17.
//

#ifndef CPP_ARCADE_LAPIN_HPP
# define CPP_ARCADE_LAPIN_HPP

# include <map>
# include <memory>
# include "lapin.h"
# include "Sound.hpp"
# include "IGfxLib.hpp"
# include "SoundManager.hpp"

namespace arcade
{
    class Bunny_picture_deleter
    {
    public:
        void operator()(t_bunny_picture* picture);
    };

    class Lapin : public IGfxLib
    {
    public:
        ~Lapin();
        Lapin();

    public:
        bool doesSupportSound() const;
        void clear();
        void soundControl(const Sound &sound);
        void loadSprites(std::vector<std::unique_ptr<ISprite>> &&sprites);
        bool pollEvent(Event &e);
        void updateGUI(IGUI &gui);
        void loadSounds(std::vector<std::pair<std::string, SoundType> > const &sounds) override;

    public:
        void updateMap(IMap const &map);
        void display();

    private:
        Lapin(Lapin const &lapin) = delete;
        Lapin &operator=(Lapin const &lapin) = delete;
        void printOneSprite(t_bunny_position const &pos, t_bunny_picture & prite);
        void printOneColor(t_bunny_position const &pos, Color color, uint32_t width, uint32_t height);
        void printText(t_bunny_position const &pos, std::string const &text);

    private:
        typedef t_bunny_context                                             t_bunny_map_context;
        typedef std::map<char, arcade::KeyboardKey>                         t_keyboard;
        typedef std::map<e_bunny_mouse_button, arcade::MouseKey >           t_mouse;
        typedef std::map<char, e_bunny_letter_tab>                          t_letters;
        typedef std::vector<std::vector<std::unique_ptr<t_bunny_picture, Bunny_picture_deleter>>>  t_sprites;
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
        static t_keyboard   Keyboard;
        static t_mouse      Mouse;
        static t_letters    Letters;
        t_sprites           Sprites;
        arcade::SoundManager SM;
    };
}

extern "C" arcade::IGfxLib *getLib();

#endif //CPP_ARCADE_LAPIN_HPP
