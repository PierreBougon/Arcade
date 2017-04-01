//
// Created by duhieu_b on 15/03/17.
//

#ifndef CPP_ARCADE_CORE_HPP
#define CPP_ARCADE_CORE_HPP

#include <iostream>
#include <vector>
#include "IGame.hpp"
#include "IGfxLib.hpp"
#include "Pars.hpp"

namespace arcade
{
    class Core
    {
    private:
        std::vector<arcade::IGfxLib *> tabLib;
        std::vector<arcade::IGame *> tabGame;
        Pars pars;

    public:
        Core();
        ~Core();
        void FeedLib();
        void FeedGame();
        void run(std::string const &lib);
    };
}

#endif //CPP_ARCADE_CORE_HPP
