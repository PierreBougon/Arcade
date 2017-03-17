//
// Created by duhieu_b on 15/03/17.
//

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

    }
}

void arcade::Core::FeedGame()
{
    for (std::vector<std::string>::const_iterator it = pars.getVecGame().begin(); it != pars.getVecGame().end(); it++)
    {

    }
}

void arcade::Core::run(std::string const& lib)
{
    pars.FeedVecLib("./lib");
    pars.FeedVecGame("./games");

}

