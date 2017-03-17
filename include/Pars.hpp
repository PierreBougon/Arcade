//
// Created by duhieu_b on 15/03/17.
//

#ifndef CPP_ARCADE_PARS_HPP
#define CPP_ARCADE_PARS_HPP

#include <iostream>
#include <vector>

namespace arcade
{
    class Pars
    {
    private:
        std::vector<std::string> vecLib;
        std::vector<std::string> vecGame;

    public:
        Pars();
        ~Pars();
        void FeedVecLib(std::string const &directory);
        void FeedVecGame(std::string const &directory);
        const std::vector<std::string> &getVecLib() const;
        const std::vector<std::string> &getVecGame() const;
    };
}

#endif //CPP_ARCADE_PARS_HPP
