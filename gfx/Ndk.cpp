//
// Created by duhieu_b on 15/03/17.
//

#include "Ndk.hpp"
#include "Gui.hpp"
#include <Protocol.hpp>
#include <curses.h>
#include <GameState.hpp>
#include <bits/unique_ptr.h>
#include <IComponent.hpp>


bool arcade::Ndk::pollEvent(arcade::Event &e)
{
    int c = getch();
    if (keyboard.find(static_cast<char>(c)) != keyboard.end())
    {
        e.action = arcade::AT_PRESSED;
        e.kb_key = keyboard[static_cast<char>(c)];
        return (true);
    }
    return false;
}

void arcade::Ndk::updateMap(arcade::IMap const &map)
{
    const ILayer &layer = map[0];
    std::vector<arcade::ITile *> vec;
    int i(0);
    int j(0);

    if (!pass)
    {
        win = newwin(static_cast<int>(map.getHeight()), static_cast<int>(map.getWidth()), getmaxy(stdscr) / 4, getmaxx(stdscr) / 4);
        pass = true;
    }
    werase(win);
    wborder(win, '|', '|', '-', '-', '-', '-', '-', '-');
    for (i = 0; i < layer.ǵetHeight(); ++i)
    {
        vec = layer[i];
        j = 0;
        for (std::vector<arcade::ITile *>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            switch ((*it)->getTypeEv())
            {
                case arcade::TileTypeEvolution::EMPTY:
                    mvwprintw(win, i, j, " ");
                    break;
                case arcade::TileTypeEvolution::BLOCK:
                    mvwprintw(win, i, j, "X");
                    break;
                case arcade::TileTypeEvolution::POWERUP:
                    mvwprintw(win, i, j, "P");
                    break;
                case arcade::TileTypeEvolution::PLAYER:
                    mvwprintw(win, i, j, "O");
                    break;
                default:
                    mvwprintw(win, i, j, " ");
                    break;
            }
        }
    }
}

void arcade::Ndk::updateGUI(arcade::IGUI const &gui)
{
    for (std::map<std::string, std::unique_ptr<IComponent>>::const_iterator it = static_cast<const arcade::Gui&>((gui)).getComponents().begin(); it != static_cast<const arcade::Gui&>((gui)).getComponents().end(); ++it)
    {
        if ((*it).second.get()->getType() == arcade::TEXT)
        {
            mvwprintw(stdscr, (*it).second.get()->getPos().second, (*it).second.get()->getPos().first, "%s",
                      (*it).second.get()->getValue().c_str());
        }
    }
}

arcade::Ndk::~Ndk()
{
    clear();
    endwin();
}

arcade::Ndk::Ndk() : keyboard({
                              {'0', arcade::KeyboardKey::KB_0},
                              {'1', arcade::KeyboardKey::KB_1},
                              {'2', arcade::KeyboardKey::KB_2},
                              {'3', arcade::KeyboardKey::KB_3},
                              {'4', arcade::KeyboardKey::KB_4},
                              {'5', arcade::KeyboardKey::KB_5},
                              {'6', arcade::KeyboardKey::KB_6},
                              {'7', arcade::KeyboardKey::KB_7},
                              {'8', arcade::KeyboardKey::KB_8},
                              {'9', arcade::KeyboardKey::KB_9},
                              {'a', arcade::KeyboardKey::KB_A},
                              {'b', arcade::KeyboardKey::KB_B},
                              {'c', arcade::KeyboardKey::KB_C},
                              {'d', arcade::KeyboardKey::KB_D},
                              {'e', arcade::KeyboardKey::KB_E},
                              {'f', arcade::KeyboardKey::KB_F},
                              {'g', arcade::KeyboardKey::KB_G},
                              {'h', arcade::KeyboardKey::KB_H},
                              {'i', arcade::KeyboardKey::KB_I},
                              {'j', arcade::KeyboardKey::KB_J},
                              {'k', arcade::KeyboardKey::KB_K},
                              {'l', arcade::KeyboardKey::KB_L},
                              {'m', arcade::KeyboardKey::KB_M},
                              {'n', arcade::KeyboardKey::KB_N},
                              {'o', arcade::KeyboardKey::KB_O},
                              {'p', arcade::KeyboardKey::KB_P},
                              {'q', arcade::KeyboardKey::KB_Q},
                              {'r', arcade::KeyboardKey::KB_R},
                              {'s', arcade::KeyboardKey::KB_S},
                              {'t', arcade::KeyboardKey::KB_T},
                              {'u', arcade::KeyboardKey::KB_U},
                              {'v', arcade::KeyboardKey::KB_V},
                              {'w', arcade::KeyboardKey::KB_W},
                              {'x', arcade::KeyboardKey::KB_X},
                              {'y', arcade::KeyboardKey::KB_Y},
                              {'z', arcade::KeyboardKey::KB_Z},
                              {KEY_DOWN, arcade::KeyboardKey::KB_ARROW_DOWN},
                              {KEY_UP, arcade::KeyboardKey ::KB_ARROW_UP},
                              {KEY_RIGHT, arcade::KeyboardKey::KB_ARROW_RIGHT},
                              {KEY_LEFT, arcade::KeyboardKey::KB_ARROW_LEFT},
                              {'&', arcade::KeyboardKey::KB_AMPERSAND},
                              {'\\', arcade::KeyboardKey::KB_ANTISLASH},
                              {'*', arcade::KeyboardKey::KB_ASTERISK},
                              {'@', arcade::KeyboardKey::KB_ATSYMBOL},
                              {KEY_BACKSPACE, arcade::KeyboardKey::KB_BACKSPACE},
                              {-1, arcade::KeyboardKey::KB_CAPSLOCK},
                              {'^', arcade::KeyboardKey::KB_CIRCUMFLEX},
                              {':', arcade::KeyboardKey::KB_COLON},
                              {',', arcade::KeyboardKey::KB_COMMA},
                              {KEY_DC, arcade::KeyboardKey::KB_DELETE},
                              {'$', arcade::KeyboardKey::KB_DOLLAR},
                              {'.', arcade::KeyboardKey::KB_DOT},
                              {'\"', arcade::KeyboardKey::KB_DOUBLEQUOTE},
                              {KEY_END, arcade::KeyboardKey::KB_END},
                              {KEY_ENTER, arcade::KeyboardKey::KB_ENTER},
                              {'=', arcade::KeyboardKey::KB_EQUAL},
                              {KEY_EXIT, arcade::KeyboardKey::KB_ESCAPE},
                              {'!', arcade::KeyboardKey::KB_EXCLAMATION},
                              {KEY_F(1), arcade::KeyboardKey::KB_FN1},
                              {KEY_F(2), arcade::KeyboardKey::KB_FN2},
                              {KEY_F(3), arcade::KeyboardKey::KB_FN3},
                              {KEY_F(4), arcade::KeyboardKey::KB_FN4},
                              {KEY_F(5), arcade::KeyboardKey::KB_FN5},
                              {KEY_F(6), arcade::KeyboardKey::KB_FN6},
                              {KEY_F(7), arcade::KeyboardKey::KB_FN7},
                              {KEY_F(8), arcade::KeyboardKey::KB_FN8},
                              {KEY_F(9), arcade::KeyboardKey::KB_FN9},
                              {KEY_F(10), arcade::KeyboardKey::KB_FN10},
                              {KEY_F(11), arcade::KeyboardKey::KB_FN11},
                              {KEY_F(12), arcade::KeyboardKey::KB_FN12},
                              {'#', arcade::KeyboardKey::KB_HASHTAG},
                              {KEY_HOME, arcade::KeyboardKey::KB_HOME},
                              {'<', arcade::KeyboardKey::KB_INFERIOR},
                              {KEY_A1 ,arcade::KeyboardKey::KB_LALT},
                              {KEY_C1,arcade::KeyboardKey::KB_LCTRL},
                              {'{', arcade::KeyboardKey::KB_LEFTBRACE},
                              {'[', arcade::KeyboardKey::KB_LEFTBRACKET},
                              {'(', arcade::KeyboardKey::KB_LEFTPAREN},
                              {KEY_SLEFT,arcade::KeyboardKey::KB_LSHIFT},
                              {'-', arcade::KeyboardKey::KB_MINUS},
                              {KEY_PPAGE ,arcade::KeyboardKey::KB_PAGEDOWN},
                              {KEY_PREVIOUS, arcade::KeyboardKey::KB_PAGEUP},
                              {'%', arcade::KeyboardKey::KB_PERCENT},
                              {'+', arcade::KeyboardKey::KB_PLUS},
                              {'?', arcade::KeyboardKey::KB_QUESTION},
                              {KEY_A3, arcade::KeyboardKey::KB_RALT},
                              {KEY_C3, arcade::KeyboardKey::KB_RCTRL},
                              {'}', arcade::KeyboardKey::KB_RIGHTBRACE},
                              {']', arcade::KeyboardKey::KB_RIGHTBRACKET},
                              {')', arcade::KeyboardKey::KB_RIGHTPAREN},
                              {KEY_SRIGHT, arcade::KeyboardKey::KB_RSHIFT},
                              {';', arcade::KeyboardKey::KB_SEMICOLON},
                              {' ', arcade::KeyboardKey::KB_SPACE},
                              {'>', arcade::KeyboardKey::KB_SUPERIOR},
                              {'\'', arcade::KeyboardKey::KB_SIMPLEQUOTE},
                              {'/', arcade::KeyboardKey ::KB_SLASH},
                              {KEY_STAB, arcade::KeyboardKey::KB_TAB},
                              {'_', arcade::KeyboardKey::KB_UNDERSCORE},
                              {'|', arcade::KeyboardKey::KB_VERTICALBAR}
                      })
{
    initscr();
    keypad(stdscr, true);
    set_escdelay(0);
    noecho();
    curs_set(0);
    pass = false;
}

void arcade::Ndk::display()
{
    refresh();
    wrefresh(win);
}

void arcade::Ndk::clear()
{
    ::clear();
}
