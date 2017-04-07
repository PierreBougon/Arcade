//
// Created by duhieu_b on 15/03/17.
//

#include <dirent.h>
#include <Logger.hpp>
#include "Pars.hpp"

arcade::Pars::Pars()
{
}

arcade::Pars::~Pars()
{
}

void arcade::Pars::FeedVecLib(std::string const &directory)
{
    try
    {
        feedVector(&vecLib, directory);
    }
    catch (std::invalid_argument error)
    {
        error.what();
    }
}

void arcade::Pars::FeedVecGame(std::string const &directory)
{
    try
    {
        feedVector(&vecGame, directory);
    }
    catch (std::invalid_argument error)
    {
        error.what();
    }
}

std::vector<std::string> const &arcade::Pars::getVecLib() const
{
    return vecLib;
}

std::vector<std::string> const &arcade::Pars::getVecGame() const
{
    return vecGame;
}


void arcade::Pars::feedVector(std::vector<std::string> *vec, std::string const &directory)
{
    DIR *dir;
    struct dirent *file;

    vec->clear();
    if ((dir = opendir(directory.c_str())))
    {
        while ((file = readdir(dir)))
        {
            vec->push_back(std::string(file->d_name));
        }
    }
    else
    {
        Logger::log(Logger::Error, "Cannot open " + directory);
        throw std::invalid_argument(directory + " is not a valid directory");
    }
    closedir(dir);
}
