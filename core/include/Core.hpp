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
        std::vector<arcade::IGfxLib *>  tabLib;
        std::vector<arcade::IGame *>    tabGame;
        Pars                            pars;
        std::string                     currentLib;
        std::string                     currentGame;

    public:
        Core();
        ~Core();

        /// Run the game loop
        void run();

        /// Init the core of the Arcade
        void init(std::string const &lib);



    private:
        void feedLib();
        void feedGame();
        int getIndexVec(std::string const &lib, std::vector<std::string> vec);
        int getIndexLib(std::string const &lib);
        int getIndexGame(std::string const &game);
    };
}

#endif //CPP_ARCADE_CORE_HPP
