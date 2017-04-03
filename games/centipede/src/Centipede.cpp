//
// Created by brout_m on 03/04/17.
//

#include <cstdlib>
#include "LifelessEntity.hpp"
#include "Centipede.hpp"

arcade::Centipede::Centipede() :
        _gameState(GameState::NONE),
        _map("./games/centipede/assets/map1.cfg", 2),
        _gui()
{
    randomize(_map, 0.1);
    _gameState = GameState::LOADING;
}

void arcade::Centipede::randomize(arcade::Map &map, double density)
{
    std::vector<Entity> entities;

    for (size_t y = 0; y < map.getHeight(); ++y)
    {
        for (size_t x = 0; x < map.getWidth(); ++x)
        {
            if (std::rand() % static_cast<int>(1.0 / density) == 0)
                entities.emplace_back(LifelessEntity({x, y}, TileType::BLOCK, TileTypeEvolution::BLOCK, Color::White, true));
        }
    }
    map.updateLayer(entities, LAYER0);
}

arcade::GameState arcade::Centipede::getGameState() const
{
    return _gameState;
}

void arcade::Centipede::notifyEvent(std::vector<arcade::Event> &&_events)
{
    std::vector<arcade::Event> events = _events;

}

void arcade::Centipede::notifyNetwork(std::vector<arcade::NetworkPacket> &&_events)
{
    std::vector<arcade::NetworkPacket> events = _events;
    (void)events;
}

std::vector<arcade::NetworkPacket> &&arcade::Centipede::getNetworkToSend()
{
    return {};
}

void arcade::Centipede::process()
{

}

std::vector<std::unique_ptr<arcade::ISprite>> &&arcade::Centipede::getSpritesToLoad() const
{
    return {};
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::Centipede::getSoundsToLoad() const
{
    return {};
}

std::vector<int> &&arcade::Centipede::getSoundsToPlay()
{
    return {};
}

const arcade::IMap &arcade::Centipede::getCurrentMap() const
{
    return _map;
}

arcade::IGUI &arcade::Centipede::getGUI()
{
    return _gui;
}