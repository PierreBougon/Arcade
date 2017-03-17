//
// Created by duhieu_b on 15/03/17.
//

#include <dirent.h>
#include "../include/Pars.hpp"

arcade::Pars::Pars()
{

}

arcade::Pars::~Pars()
{

}

void arcade::Pars::FeedVecLib(std::string const &directory)
{
    DIR *dir;
    struct dirent *file;

    if ((dir = opendir(directory.c_str())))
    {
        while ((file = readdir(dir)))
        {
            vecLib.push_back(std::string(file->d_name));
        }
    }
    closedir(dir);
}

void arcade::Pars::FeedVecGame(std::string const &directory)
{
    DIR *dir;
    struct dirent *file;

    if ((dir = opendir(directory.c_str())))
    {
        while ((file = readdir(dir)))
        {
            vecGame.push_back(std::string(file->d_name));
        }
    }
    closedir(dir);
}

const std::vector<std::string> &arcade::Pars::getVecLib() const
{
    return vecLib;
}

const std::vector<std::string> &arcade::Pars::getVecGame() const
{
    return vecGame;
}
