//
// Created by brout_m on 03/04/17.
//

#include <cstdlib>
#include "LifelessEntity.hpp"
#include "CentipedeGame.hpp"

arcade::CentipedeGame::CentipedeGame() :
        _gameState(GameState::NONE),
        _map("./games/centipede/assets/map1.cfg", LASTLAYER),
        _gui(),
        _bullet({0, 0}),
        _centipedeKiller(placePlayer(_map),
                         TileType::OTHER,
                         TileTypeEvolution::PLAYER,
                         Color::Cyan,
                         1,
                         _map,
                         _mushrooms,
                         _centipedes,
                         _bullet)
{
    randomize(_map, 0.1);
    _gameState = GameState::LOADING;
}

void arcade::CentipedeGame::randomize(arcade::Map &map, double density)
{
    for (size_t y = 0; y < map.getHeight(); ++y)
    {
        for (size_t x = 0; x < map.getWidth(); ++x)
        {
            Vector2s vec(x, y);

            if (_centipedeKiller.getAbs() != vec && std::rand() % static_cast<int>(1.0 / density) == 0)
                _mushrooms.emplace_back(Mushroom(vec));
        }
    }

    for (Entity &entity : _mushrooms)
        map.updateLayer(entity, PLAYER);
}

arcade::GameState arcade::CentipedeGame::getGameState() const
{
    return _gameState;
}

void arcade::CentipedeGame::notifyEvent(std::vector<arcade::Event> &&_events)
{
    std::vector<arcade::Event> events = std::move(_events);
    _centipedeKiller.updatePlayerInput(events);
}

void arcade::CentipedeGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&_events)
{
    std::vector<arcade::NetworkPacket> events = _events;
    (void)events;
}

std::vector<arcade::NetworkPacket> &&arcade::CentipedeGame::getNetworkToSend()
{
    std::vector<arcade::NetworkPacket> npt;
    return std::move(npt);
}

void arcade::CentipedeGame::createCentipede()
{
    Vector2s pos;

    pos.x = rand() % _map.getWidth();
    pos.y = 0;
    _centipedes.emplace_back(Centipede(pos));
}

void arcade::CentipedeGame::process()
{
    if (_gameState != INGAME)
        _gameState = INGAME;

    if (!_centipedes.size())
        createCentipede();

    _centipedeKiller.move();
    _centipedeKiller.action();

    for (Centipede &centipede : _centipedes)
    {
        centipede.oneTurn(_bullet, _centipedes, _mushrooms, _map);
    }

    _centipedeKiller.touched();

    if (!_centipedeKiller.getHp())
        _gameState = QUIT;
}

std::vector<std::unique_ptr<arcade::ISprite>> &&arcade::CentipedeGame::getSpritesToLoad() const
{
    std::vector<std::unique_ptr<arcade::ISprite>> sprt;

    return std::move(sprt);
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::CentipedeGame::getSoundsToLoad() const
{
    std::vector<std::pair<std::string, arcade::SoundType>> sounds;

    return std::move(sounds);
}

std::vector<int> &&arcade::CentipedeGame::getSoundsToPlay()
{
    std::vector<int> sounds;

    return std::move(sounds);
}

const arcade::IMap &arcade::CentipedeGame::getCurrentMap() const
{
    return _map;
}

arcade::IGUI &arcade::CentipedeGame::getGUI()
{
    return _gui;
}

arcade::Vector2s &&arcade::CentipedeGame::placePlayer(arcade::Map &map)
{
    Vector2s pos;
    size_t height = map.getHeight();
    size_t width = map.getWidth();

    pos.x = std::rand() % width;
    pos.y = std::rand() % static_cast<size_t>(static_cast<double>(height) * 0.2 + static_cast<double>(width) * 0.8);
    return std::move(pos);
}

void arcade::CentipedeGame::updateMap()
{
    _map.resetMapFromLayer(PLAYER);
    _map.updateLayer(_centipedeKiller, CentipedeLayers::PLAYER);
    for (Mushroom &mushroom : _mushrooms)
        _map.updateLayer(mushroom, CentipedeLayers::PLAYER);

    _map.updateLayer(_bullet, CentipedeLayers::BULLET);

    for (Centipede &centipede : _centipedes)
        for (CentipedePart &part : centipede.getBody())
            _map.updateLayer(part, CentipedeLayers::CENTIPEDE);
}

extern "C" arcade::IGame *getGame()
{
    return (new arcade::CentipedeGame());
}