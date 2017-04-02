//
// Created by duhieu_b on 15/03/17.
//

#include <DLLoader.hpp>
#include "../include/Core.hpp"

arcade::Core::Core()
{
}

arcade::Core::~Core()
{
}

void arcade::Core::init(std::string const &lib)
{
    pars.FeedVecLib("./lib");
    pars.FeedVecGame("./games");
    feedLib();
    feedGame();
    currentLib = lib;

    // Basic choice should be decided on a menu
    currentGame = "./games/snake/snake.so";
}

void arcade::Core::run()
{
    int         idx;
    IGfxLib     *lib;
    IGame       *game;

    if ((idx = getIndexLib(currentLib)) == -1)
        return ;

    // Init lib and game for this game loop
    lib = tabLib[idx];
    game =  tabGame[getIndexGame(currentGame)];

    lib->updateGUI(game->getGUI());
    lib->display();
}

void arcade::Core::feedLib()
{
    for (std::vector<std::string>::const_iterator it = pars.getVecLib().begin(); it != pars.getVecLib().end(); it++)
    {
        DLLoader loader(*it);
        tabLib.push_back(loader.getInstance("getLib"));
    }
}

void arcade::Core::feedGame()
{
    for (std::vector<std::string>::const_iterator it = pars.getVecGame().begin(); it != pars.getVecGame().end(); it++)
    {
        DLLoader loader(*it);
        tabGame.push_back(loader.getInstance("getGame"));
    }
}

int arcade::Core::getIndexLib(std::string const &lib)
{
    return (getIndexVec(lib, pars.getVecLib()));
}

int arcade::Core::getIndexGame(std::string const &game)
{
    return (getIndexVec(game, pars.getVecGame()));
}

int arcade::Core::getIndexVec(std::string const &lib, std::vector<std::string> vec)
{
    int i = 0;

    for (std::vector<std::string>::const_iterator it = pars.getVecLib().begin(); it != pars.getVecLib().end(); ++it)
    {
        if (*it == lib)
            return i;
        ++i;
    }
    return (-1);
}
