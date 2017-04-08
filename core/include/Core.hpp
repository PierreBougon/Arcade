//
// Created by Pierre Bougon on 15/03/17.
//

#ifndef CPP_ARCADE_CORE_HPP
#define CPP_ARCADE_CORE_HPP

#include <iostream>
#include <vector>
#include "AGame.hpp"
#include "IGfxLib.hpp"
#include "Pars.hpp"
#include "DLLoader.hpp"

namespace arcade
{
    class Core
    {
    private:
        std::vector<arcade::IGfxLib *>                 tabLib;
        std::vector<arcade::IGame *>                   tabGame;
        Pars                                           pars;
        bool                                           open;
        std::vector<Event>                             events;
        std::unique_ptr<DLLoader<IGfxLib>>             sound;

        // Pointers on current instance of lib & game
        // They contain raw address of unique_ptr from vectors tabLib & tabGame
        // DO NOT free those pointers nor delete them
        IGfxLib                                        *currentLib;
        IGame                                          *currentGame;

    public:
        Core();
        Core(std::string const &lib);
        ~Core();

        /// Run the game loop
        void run();

        /// Init the core of the Arcade
        void init(std::string const &lib);

        bool isOpen() const;


    private:
        void feedLib();
        void feedGame();
        void feedSound();
        int getIndexVec(std::string const &lib, std::vector<std::string> vec) const;
        int getIndexLib(std::string const &lib) const;
        int getIndexGame(std::string const &game) const;

        /// Find corresponding instance of game or lib
        IGame   *findGame(const std::string &game);
        IGfxLib *findLib(const std::string &lib);

        /// Methods relative to the GameState
        void drawFrame();
        void initGame();
        void quitGame();
        void quitArcade();

        /// Encapsulate the sound calls
        void playSound();

        /// Encapsulate the networks calls
        void sendNetwork();

        void manageEvents();

        void loadDependencies();


        /**************************************************************************************
         * Some error messages to make the code easier to understand and more beautiful
         **************************************************************************************/
    private:
        static const std::string NO_LIB_ERROR_MSG;
        static const std::string NO_GAME_ERROR_MSG;

    };
}

#endif //CPP_ARCADE_CORE_HPP
