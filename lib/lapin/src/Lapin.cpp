//
// Created by brout_m on 16/03/17.
//

#include <exception>
#include <memory>
#include "Lapin.hpp"

t_bunny_response keyboardPollEvents(t_bunny_event_state state,
                                    t_bunny_keysym symbole,
                                    void *data)
{
    (void)data;
    (void)state;
    (void)symbole;
    return (GO_ON);
}

t_bunny_response mainLoop(void *data)
{
    (void)data;
    return (EXIT_ON_SUCCESS);
}

t_bunny_response mousePollEvents(t_bunny_event_state state,
                                 t_bunny_mouse_button button,
                                 void *data)
{
    (void)state;
    (void)button;
    (void)data;
    return (GO_ON);
}

t_bunny_response mouseMovement(const t_bunny_position *pos,
                               void *data)
{
    (void)pos;
    (void)data;
    return (GO_ON);
}

arcade::Lapin::~Lapin()
{
    if (Window != nullptr)
        bunny_stop(Window);
    if (Map != nullptr)
        bunny_delete_clipable(Map);
    for (std::pair<const size_t, t_bunny_effect *> &effect : Effects)
    {
        if (effect.second != nullptr) {
            bunny_sound_stop(&effect.second->sound);
            bunny_delete_sound(&effect.second->sound);
        }
    }
    for (std::pair<const size_t, t_bunny_music *> &music : Musics)
    {
        if (music.second != nullptr) {
            bunny_sound_stop(&music.second->sound);
            bunny_delete_sound(&music.second->sound);
        }
    }
    for (std::vector<t_bunny_picture *> &vec : Sprites)
    {
        for (t_bunny_picture *&sprite : vec)
        {
            if (sprite != nullptr)
                bunny_delete_clipable(sprite);
        }
    }
}

bool arcade::Lapin::doesSupportSound() const
{
    return true;
}

void arcade::Lapin::display()
{
    bunny_blit(&Window->buffer, Map, NULL);
    bunny_display(Window);
}

void arcade::Lapin::clear()
{
    bunny_clear(&Window->buffer, BLACK);
}

void arcade::Lapin::loadSounds(std::vector<std::pair<std::string, SoundType> > const &sounds)
{
    size_t i(0);

    for (std::pair<std::string, SoundType> const& sound : sounds)
    {
        if (sound.second == SoundType::MUSIC)
        {
            Musics[i] = bunny_load_music(sound.first.c_str());
            if (!Musics[i])
                throw std::bad_alloc();
        }
        else
        {
            Effects[i] = bunny_load_effect(sound.first.c_str());
            if (!Effects[i])
                throw std::bad_alloc();
        }
        ++i;
    }
}

void arcade::Lapin::soundControl(const Sound &sound)
{
    t_bunny_map_music::iterator musicIt;
    t_bunny_map_effect::iterator effectIt;
    t_bunny_sound *snd;

    musicIt = Musics.find(sound.id);
    effectIt = Effects.find(sound.id);

    snd = musicIt != Musics.end() ? &musicIt->second->sound :
          effectIt != Effects.end() ? &effectIt->second->sound : nullptr;

    if (snd != nullptr)
        switch (sound.mode)
        {
            case (UNIQUE) :
                bunny_sound_play(snd);
                bunny_sound_loop(snd, false);
                break;
            case (REPEAT) :
                bunny_sound_play(snd);
                bunny_sound_loop(snd, true);
                break;
            case (VOLUME) :
                bunny_sound_volume(snd, sound.volume);
                break;
            case (STOP):
                bunny_sound_stop(snd);
                bunny_sound_loop(snd, false);
                break;
            case (PLAY) :
                bunny_sound_play(snd);
                break;
            case (PAUSE) :
                bunny_sound_stop(snd);
                break;
            case (RESUME) :
                bunny_sound_play(snd);
                break;
        }
}

bool arcade::Lapin::pollEvent(arcade::Event &e)
{
    static int iKey = -1;
    static int iMouse = -1;
    static const bool *keyboard = bunny_get_keyboard();
    static const bool *mouse = bunny_get_mouse_button();
    static const t_bunny_position *pos = bunny_get_mouse_position();

    bunny_loop(Window, 60, nullptr);
    while (iKey < BKS_LAST_KEY)
    {
        ++iKey;
        if (keyboard[iKey] && Keyboard.find(iKey) != Keyboard.end()) {
            e.type = ET_KEYBOARD;
            e.action = AT_PRESSED;
            e.kb_key = Keyboard[iKey];
            e.pos_abs.x = pos->x;
            e.pos_abs.y = pos->y;
            return (true);
        }
    }
    while (iMouse < LAST_BUNNY_MOUSEBUTTON)
    {
        ++iMouse;
        if (mouse[iMouse] && Mouse.find(static_cast<e_bunny_mouse_button>(iMouse)) != Mouse.end()) {
            e.type = ET_MOUSE;
            e.action = AT_PRESSED;
            e.m_key = Mouse[static_cast<e_bunny_mouse_button>(iMouse)];
            e.pos_abs.x = pos->x;
            e.pos_abs.y = pos->y;
            return (true);
        }
    }
    iMouse = -1;
    iKey = -1;
    e.type = ET_NONE;
    e.action = AT_NONE;
    e.kb_key = KB_NONE;
    e.pos_abs.x = pos->x;
    e.pos_abs.y = pos->y;
    return (false);
}

void arcade::Lapin::printOneSprite(t_bunny_position const &pos, t_bunny_picture &sprite)
{
    sprite.scale.y = 1.0 / (static_cast<double>(sprite.clip_height) / static_cast<double>(TileHeight));
    sprite.scale.x = 1.0 / (static_cast<double>(sprite.clip_width) / static_cast<double>(TileWidth));
    bunny_blit(&Map->buffer, &sprite, &pos);
}

void arcade::Lapin::printOneColor(t_bunny_position const &pos, Color color, uint32_t width, uint32_t height)
{
    static t_bunny_picture *pic = bunny_new_picture(Width, Height);

    if (pic != nullptr)
    {
        pic->clip_height = height;
        pic->clip_width = width;
        bunny_fill(&pic->buffer, color.full);
        bunny_blit(&Map->buffer, pic, &pos);
    }
}

void arcade::Lapin::updateMap(const arcade::IMap &map)
{
    size_t nbLayers = map.getLayerNb();
    size_t mHeight = map.getHeight();
    size_t mWidth = map.getWidth();
    t_bunny_position pos;

    for (size_t layers = 0; layers < nbLayers; ++layers)
    {
        pos.y = 0;
        for (size_t y = 0; y < mHeight; ++y)
        {
            pos.x = 0;
            for (size_t x = 0; x < mWidth; ++x)
            {
                const ITile& tile = map.at(layers, x, y);

                if (tile.hasSprite())
                    printOneSprite(pos, *Sprites[tile.getSpriteId()][tile.getSpritePos()]);
                else
                    printOneColor(pos, tile.getColor(), TileWidth, TileHeight);
                pos.x += TileWidth;
            }
            pos.y += TileHeight;
        }
    }
}

void arcade::Lapin::printText(t_bunny_position const &, std::string const &)
{
}

void arcade::Lapin::updateGUI(arcade::IGUI &gui)
{
    t_bunny_position pos;
    uint32_t width;
    uint32_t height;

    for (size_t i = 0; i < gui.size(); ++i)
    {
        IComponent &component = gui.at(i);

        pos.x = static_cast<int>(component.getX() * static_cast<double>(Width));
        pos.y = static_cast<int>(component.getY() * static_cast<double>(Height));
        width = static_cast<uint32_t>(component.getWidth() * static_cast<double>(Width));
        height = static_cast<uint32_t>(component.getHeight() * static_cast<double>(Height));

        if (component.hasSprite())
            printOneSprite(pos, *Sprites[component.getBackgroundId()][0]);
        else
            printOneColor(pos, component.getBackgroundColor(), width, height);

        printText(pos, component.getText());
    }
}

void arcade::Lapin::loadSprites(std::vector<std::unique_ptr<arcade::ISprite>> &&sprites)
{
    std::vector<t_bunny_picture *> add;

    for (std::unique_ptr<arcade::ISprite> &sprite : sprites)
    {
        for (size_t i = 0; i < sprite->spritesCount(); ++i)
        {
            add.emplace_back(bunny_load_picture(sprite->getGraphicPath(i).c_str()));
            if (!add.back())
                throw std::bad_alloc();
        }
        Sprites.emplace_back(std::move(add));
    }
}

arcade::Lapin::Lapin() :
        Width(800),
        Height(600),
        TileWidth(10),
        TileHeight(10),
        X(0),
        Y(0),
        Window(nullptr),
        Map(nullptr),
        Context({})
{
    bunny_enable_full_blit(true);
    Map = bunny_new_picture(Width, Height);
    if (Map == nullptr)
        throw std::bad_alloc();
    Window = bunny_start(Width, Height, false, "Retro Furnace");
    if (Window == nullptr)
        throw std::bad_alloc();

    Context.key = keyboardPollEvents;
    Context.loop = mainLoop;
    Context.click = mousePollEvents;
    Context.move = mouseMovement;
    bunny_set_context(&Context);
}

void arcade::Bunny_picture_deleter::operator()(t_bunny_picture *picture)
{
    bunny_delete_clipable(picture);
}

void arcade::Bunny_sound_deleter::operator()(t_bunny_effect *sound) {
    bunny_sound_stop(&sound->sound);
    bunny_delete_sound(&sound->sound);
}

void arcade::Bunny_music_deleter::operator()(t_bunny_music *sound) {
    bunny_sound_stop(&sound->sound);
    bunny_delete_sound(&sound->sound);
}

namespace arcade
{
    Lapin::t_keyboard Lapin::Keyboard = {
            {BKS_0, arcade::KeyboardKey::KB_0},
            {BKS_1, arcade::KeyboardKey::KB_1},
            {BKS_2, arcade::KeyboardKey::KB_2},
            {BKS_3, arcade::KeyboardKey::KB_3},
            {BKS_4, arcade::KeyboardKey::KB_4},
            {BKS_5, arcade::KeyboardKey::KB_5},
            {BKS_6, arcade::KeyboardKey::KB_6},
            {BKS_7, arcade::KeyboardKey::KB_7},
            {BKS_8, arcade::KeyboardKey::KB_8},
            {BKS_9, arcade::KeyboardKey::KB_9},
            {BKS_A, arcade::KeyboardKey::KB_A},
            {BKS_B, arcade::KeyboardKey::KB_B},
            {BKS_C, arcade::KeyboardKey::KB_C},
            {BKS_D, arcade::KeyboardKey::KB_D},
            {BKS_E, arcade::KeyboardKey::KB_E},
            {BKS_F, arcade::KeyboardKey::KB_F},
            {BKS_G, arcade::KeyboardKey::KB_G},
            {BKS_H, arcade::KeyboardKey::KB_H},
            {BKS_I, arcade::KeyboardKey::KB_I},
            {BKS_J, arcade::KeyboardKey::KB_J},
            {BKS_K, arcade::KeyboardKey::KB_K},
            {BKS_L, arcade::KeyboardKey::KB_L},
            {BKS_M, arcade::KeyboardKey::KB_M},
            {BKS_N, arcade::KeyboardKey::KB_N},
            {BKS_O, arcade::KeyboardKey::KB_O},
            {BKS_P, arcade::KeyboardKey::KB_P},
            {BKS_Q, arcade::KeyboardKey::KB_Q},
            {BKS_R, arcade::KeyboardKey::KB_R},
            {BKS_S, arcade::KeyboardKey::KB_S},
            {BKS_T, arcade::KeyboardKey::KB_T},
            {BKS_U, arcade::KeyboardKey::KB_U},
            {BKS_V, arcade::KeyboardKey::KB_V},
            {BKS_W, arcade::KeyboardKey::KB_W},
            {BKS_X, arcade::KeyboardKey::KB_X},
            {BKS_Y, arcade::KeyboardKey::KB_Y},
            {BKS_Z, arcade::KeyboardKey::KB_Z},
            {BKS_DOWN, arcade::KeyboardKey::KB_ARROW_DOWN},
            {BKS_UP, arcade::KeyboardKey ::KB_ARROW_UP},
            {BKS_RIGHT, arcade::KeyboardKey::KB_ARROW_RIGHT},
            {BKS_LEFT, arcade::KeyboardKey::KB_ARROW_LEFT},
            {'&', arcade::KeyboardKey::KB_AMPERSAND},
            {'\\', arcade::KeyboardKey::KB_BACKSLASH},
            {'*', arcade::KeyboardKey::KB_ASTERISK},
            {'@', arcade::KeyboardKey::KB_ATSYMBOL},
            {BKS_BACKSPACE, arcade::KeyboardKey::KB_BACKSPACE},
            {-1, arcade::KeyboardKey::KB_CAPSLOCK},
            {'^', arcade::KeyboardKey::KB_CIRCUMFLEX},
            {':', arcade::KeyboardKey::KB_COLON},
            {',', arcade::KeyboardKey::KB_COMMA},
            {BKS_DELETE, arcade::KeyboardKey::KB_DELETE},
            {'$', arcade::KeyboardKey::KB_DOLLAR},
            {'.', arcade::KeyboardKey::KB_DOT},
            {'\"', arcade::KeyboardKey::KB_DOUBLEQUOTE},
            {BKS_END, arcade::KeyboardKey::KB_END},
            {BKS_RETURN, arcade::KeyboardKey::KB_ENTER},
            {'=', arcade::KeyboardKey::KB_EQUALS},
            {BKS_ESCAPE, arcade::KeyboardKey::KB_ESCAPE},
            {'!', arcade::KeyboardKey::KB_EXCLAMATION},
            {BKS_F1, arcade::KeyboardKey::KB_FN1},
            {BKS_F2, arcade::KeyboardKey::KB_FN2},
            {BKS_F3, arcade::KeyboardKey::KB_FN3},
            {BKS_F4, arcade::KeyboardKey::KB_FN4},
            {BKS_F5, arcade::KeyboardKey::KB_FN5},
            {BKS_F6, arcade::KeyboardKey::KB_FN6},
            {BKS_F7, arcade::KeyboardKey::KB_FN7},
            {BKS_F8, arcade::KeyboardKey::KB_FN8},
            {BKS_F9, arcade::KeyboardKey::KB_FN9},
            {BKS_F10, arcade::KeyboardKey::KB_FN10},
            {BKS_F11, arcade::KeyboardKey::KB_FN11},
            {BKS_F12, arcade::KeyboardKey::KB_FN12},
            {'#', arcade::KeyboardKey::KB_HASHTAG},
            {BKS_HOME, arcade::KeyboardKey::KB_HOME},
            {'<', arcade::KeyboardKey::KB_INFERIOR},
            {BKS_LALT, arcade::KeyboardKey::KB_LALT},
            {BKS_LCONTROL, arcade::KeyboardKey::KB_LCTRL},
            {'{', arcade::KeyboardKey::KB_LEFTBRACE},
            {'[', arcade::KeyboardKey::KB_LEFTBRACKET},
            {'(', arcade::KeyboardKey::KB_LEFTPAREN},
            {BKS_LSHIFT, arcade::KeyboardKey::KB_LSHIFT},
            {'-', arcade::KeyboardKey::KB_MINUS},
            {BKS_PAGEDOWN ,arcade::KeyboardKey::KB_PAGEDOWN},
            {BKS_PAGEUP, arcade::KeyboardKey::KB_PAGEUP},
            {'%', arcade::KeyboardKey::KB_PERCENT},
            {'+', arcade::KeyboardKey::KB_PLUS},
            {'?', arcade::KeyboardKey::KB_QUESTION},
            {BKS_RALT, arcade::KeyboardKey::KB_RALT},
            {BKS_RCONTROL, arcade::KeyboardKey::KB_RCTRL},
            {'}', arcade::KeyboardKey::KB_RIGHTBRACE},
            {']', arcade::KeyboardKey::KB_RIGHTBRACKET},
            {')', arcade::KeyboardKey::KB_RIGHTPAREN},
            {BKS_RSHIFT, arcade::KeyboardKey::KB_RSHIFT},
            {';', arcade::KeyboardKey::KB_SEMICOLON},
            {' ', arcade::KeyboardKey::KB_SPACE},
            {'>', arcade::KeyboardKey::KB_SUPERIOR},
            {'\'', arcade::KeyboardKey::KB_SIMPLEQUOTE},
            {'/', arcade::KeyboardKey ::KB_SLASH},
            {BKS_TAB, arcade::KeyboardKey::KB_TAB},
            {'_', arcade::KeyboardKey::KB_UNDERSCORE},
            {'|', arcade::KeyboardKey::KB_VERTICALBAR}
    };

    Lapin::t_mouse Lapin::Mouse = {
            {BMB_RIGHT, arcade::MouseKey::M_RIGHT_CLICK},
            {BMB_LEFT, arcade::MouseKey::M_LEFT_CLICK},
            {BMB_MIDDLE, arcade::MouseKey::M_MIDDLE_CLICK},
            {BMB_EXTRABUTTON0, arcade::MouseKey::M_BT0},
            {BMB_EXTRABUTTON1, arcade::MouseKey::M_BT1}
    };

    Lapin::t_letters Lapin::Letters = {
            {'a', BFT_A},
            {'b', BFT_B},
            {'c', BFT_C},
            {'d', BFT_D},
            {'e', BFT_E},
            {'f', BFT_F},
            {'g', BFT_G},
            {'h', BFT_H},
            {'i', BFT_I},
            {'j', BFT_J},
            {'k', BFT_K},
            {'l', BFT_L},
            {'m', BFT_M},
            {'n', BFT_N},
            {'o', BFT_O},
            {'p', BFT_P},
            {'q', BFT_Q},
            {'r', BFT_R},
            {'s', BFT_S},
            {'t', BFT_T},
            {'u', BFT_U},
            {'v', BFT_V},
            {'w', BFT_W},
            {'x', BFT_X},
            {'y', BFT_Y},
            {'z', BFT_Z},
            {'!', BFT_EXCLAMATION},
            {'0', BFT_0},
            {'1', BFT_1},
            {'2', BFT_2},
            {'3', BFT_3},
            {'4', BFT_4},
            {'5', BFT_5},
            {'6', BFT_6},
            {'7', BFT_7},
            {'8', BFT_8},
            {'9', BFT_9}
    };
};