//
// Created by duhieu_b on 03/04/17.
//

#ifndef CPP_ARCADE_SNAKE_HPP
#define CPP_ARCADE_SNAKE_HPP


#include "IGame.hpp"
#include "Gui.hpp"
#include "Map.hpp"
#include "Sound.hpp"
#include "DestroyableObject.hpp"
#include "PlayerControlSnake.hpp"

namespace arcade
{
    class Snake : public IGame
    {
    private:
        Map gameMap;
        Gui gameGui;
        GameState state;
        std::vector<PlayerControlSnake> snakes;
        std::vector<DestroyableObject> cherry;

        bool checkInSnake(Vector2s const& pos);
        void checkEat();
        void checkDead();
        void feedingSnakes();
        void createPlayer();
        void putFoodInMap();
        void moveBody();
    public:
        Snake();
        GameState getGameState() const;
        void notifyEvent(std::vector<Event> &&events);
        void notifyNetwork(std::vector<NetworkPacket> &&events);
        std::vector<NetworkPacket> &&getNetworkToSend();
        void process();
        std::vector<std::unique_ptr<ISprite>> &&getSpritesToLoad() const;
        std::vector<std::pair<std::string, arcade::SoundType>> getSoundsToLoad() const;
        std::vector<int> &&getSoundsToPlay();
        const IMap &getCurrentMap() const;
        const IGUI &getGUI() const;
    };
}

#endif //CPP_ARCADE_SNAKE_HPP
