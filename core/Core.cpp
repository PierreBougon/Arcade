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

void arcade::Core::FeedLib()
{
    for (std::vector<std::string>::const_iterator it = pars.getVecLib().begin(); it != pars.getVecLib().end(); it++)
    {
        DLLoader loader(*it);
        tabLib.push_back(loader.getInstance("getClone"));
    }
}

void arcade::Core::FeedGame()
{
    for (std::vector<std::string>::const_iterator it = pars.getVecGame().begin(); it != pars.getVecGame().end(); it++)
    {
        DLLoader loader(*it);
        tabGame.push_back(loader.getInstance("getClone"));
    }
}

void arcade::Core::run(std::string const& lib)
{
    int idx;

    pars.FeedVecLib("./lib");
    pars.FeedVecGame("./games");
    FeedLib();
    FeedGame();
    if ((idx = recupIndexLib(lib)) == -1)
        return ;
    tabLib[idx]->updateGUI();
    tabLib[idx]->display();
}

int arcade::Core::recupIndexLib(std::string const &lib)
{
    int i(0);
    for (std::vector<std::string>::const_iterator it = pars.getVecLib().begin(); it != pars.getVecLib().end(); it++)
    {
        if (*it == lib)
        {
            return i;
        }
        i++;
    }
    return (-1);
}

