//
// Created by brout_m on 03/04/17.
//

#ifndef CPP_ARCADE_CENTIPEDE_HPP
# define CPP_ARCADE_CENTIPEDE_HPP

# include <list>
# include "IGame.hpp"
# include "Map.hpp"
# include "Gui.hpp"
# include "CentipedeKiller.hpp"

namespace arcade
{
    class CentipedeGame : public IGame
    {
    public:
        enum CentipedeLayers
        {
            LAYER0 = 0,
            PLAYER,
            BULLET,
            CENTIPEDE,
            LASTLAYER
        };

    public:
        ~CentipedeGame() {};
        CentipedeGame();
        GameState getGameState() const;
        void notifyEvent(std::vector<Event> &&events);
        void notifyNetwork(std::vector<NetworkPacket> &&events);
        void process();
        const IMap &getCurrentMap() const;
        IGUI &getGUI();
        std::vector<NetworkPacket> &&getNetworkToSend();
        std::vector<std::unique_ptr<ISprite>> &&getSpritesToLoad() const;
        std::vector<std::pair<std::string, SoundType>> getSoundsToLoad() const;
        std::vector<int> &&getSoundsToPlay();

    private:
        arcade::GameState               _gameState;
        Map                             _map;
        Gui                             _gui;
        CentipedeKiller                 _centipedeKiller;
        Bullet                          _bullet;
        std::list<Entity>               _mushrooms;
        std::list<std::list<Entity>>    _entities;

    // private functions
        void randomize(Map &map, double density = 0.5);
        Vector2s &&placePlayer(Map &map);
    };
}

#endif //CPP_ARCADE_CENTIPEDE_HPP
