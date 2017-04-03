//
// Created by duhieu_b on 03/04/17.
//

#ifndef CPP_ARCADE_SNAKE_HPP
#define CPP_ARCADE_SNAKE_HPP


#include <IGame.hpp>
#include <Gui.hpp>
#include <Map.hpp>

namespace arcade
{
    enum PlayerInputs
    {
        I_NONE = -1,
        MOVE_UP,
        MOVE_DOWW,
        MOVE_RIGHT,
        MOVE_LEFT,
        NB_IMPUTS
    };

    /*enum actionPlayer
    {
        A_NONE = -1,
        MOVE,
        EAT,
        GROWN_UP
    };*/

    class Snake : public IGame
    {
        Map gameMap;
        Gui gameGui;
        PlayerInputs move;
//        actionPlayer action;
        GameState state;
        std::vector<Entity> entities;
    public:
        Snake();
        GameState getGameState() const;
        void notifyEvent(std::vector<Event> &&events);
        void notifyNetwork(std::vector<NetworkPacket> &&events);
        std::vector<NetworkPacket> &&getNetworkToSend();
        void process();
        std::vector<std::unique_ptr<ISprite>> &&getSpritesToLoad() const;
        std::vector<std::string> getSoundsToLoad() const;
        std::vector<int> &&getSoundsToPlay();
        const IMap &getCurrentMap() const;
        const IGUI &getGUI() const;
        PlayerInputs getMove() const;
        //actionPlayer getAction() const;
        void createPlayer();
        void putFoodInMap();
    };
}

#endif //CPP_ARCADE_SNAKE_HPP
