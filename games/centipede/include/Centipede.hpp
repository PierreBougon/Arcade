//
// Created by brout_m on 03/04/17.
//

#ifndef CPP_ARCADE_CENTIPEDE_HPP
# define CPP_ARCADE_CENTIPEDE_HPP

# include "IGame.hpp"
# include "Map.hpp"
# include "Gui.hpp"

namespace arcade
{
    class Centipede : public IGame 
    {
    public:
        enum CentipedeLayers
        {
            LAYER0 = 0,
            PLAYER,
        };

    public:
        ~Centipede() {};
        Centipede();
        GameState getGameState() const;
        void notifyEvent(std::vector<Event> &&events);
        void notifyNetwork(std::vector<NetworkPacket> &&events);
        std::vector<NetworkPacket> &&getNetworkToSend();
        void process();
        std::vector<std::unique_ptr<ISprite>> &&getSpritesToLoad() const;
        std::vector<std::pair<std::string, SoundType>> getSoundsToLoad() const;
        std::vector<int> &&getSoundsToPlay();
        const IMap &getCurrentMap() const;
        IGUI &getGUI();

    private:
        arcade::GameState _gameState;
        Map _map;
        Gui _gui;

    // private functions
        void randomize(Map &map, double density = 0.5);
    };
}

#endif //CPP_ARCADE_CENTIPEDE_HPP
