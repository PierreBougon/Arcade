//
// Created by duhieu_b on 15/03/17.
//

#include <dirent.h>
#include "Pars.hpp"

arcade::Pars::Pars()
{

}

arcade::Pars::~Pars()
{

}

void arcade::Pars::FeedVecLib(std::string const &directory)
{
    feedVector(&vecLib, directory);
}

void arcade::Pars::FeedVecGame(std::string const &directory)
{
    feedVector(&vecGame, directory);
}

const std::vector<std::string> &arcade::Pars::getVecLib() const
{
    return vecLib;
}

const std::vector<std::string> &arcade::Pars::getVecGame() const
{
    return vecGame;
}

void arcade::Pars::feedVector(std::vector<std::string> *vec, std::string const &directory)
{
    DIR *dir;
    struct dirent *file;

    if ((dir = opendir(directory.c_str())))
    {
        while ((file = readdir(dir)))
        {
            vec->push_back(std::string(file->d_name));
        }
    }
    closedir(dir);
}
