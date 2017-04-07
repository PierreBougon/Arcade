//
// Created by brout_m on 03/04/17.
//

#include <new>
#include <cstdlib>
#include <unistd.h>
#include "LifelessEntity.hpp"
#include "CentipedeGame.hpp"
#include "Protocol.hpp"

arcade::CentipedeGame::CentipedeGame() :
        _gameState(GameState::NONE),
        _map("./games/centipede/assets/map1.cfg", LASTLAYER),
        _gui(),
        _bullet(Vector2s(0, 0)),
        _centipedeKiller(placePlayer(_map),
                         TileType::EMPTY,
                         TileTypeEvolution::PLAYER,
                         Color::Cyan,
                         1,
                         _map,
                         _mushrooms,
                         _centipedes,
                         _bullet)
{
    _map.updateLayer(_centipedeKiller, PLAYER);
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
                _mushrooms.push_back(new Mushroom(vec));
        }
    }

    for (Entity *entity : _mushrooms)
        map.updateLayer(*entity, PLAYER);
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
    _centipedes.emplace_back(new Centipede(pos));
}

void arcade::CentipedeGame::process()
{
    std::cerr << "start process" << std::endl;
    if (_gameState != INGAME)
        _gameState = INGAME;

    std::cerr << "creating centiped" << std::endl;
    if (!_centipedes.size())
        createCentipede();

    std::cerr << "moving player" << std::endl;
    _centipedeKiller.move();
    _centipedeKiller.action();

    std::cerr << "moving centiped" << std::endl;
    for (Centipede *centipede : _centipedes)
    {
        centipede->oneTurn(_bullet, _centipedes, _mushrooms, _map);
    }

    std::cerr << "killing centiped" << std::endl;
    _centipedeKiller.touched();

    std::cerr << "updating map" << std::endl;
    this->updateMap();

    std::cerr << "player hp" << std::endl;
    if (!_centipedeKiller.getHp())
        _gameState = QUIT;
    std::cerr << "end process" << std::endl;
}

std::vector<std::unique_ptr<arcade::ISprite>> arcade::CentipedeGame::getSpritesToLoad() const
{
    std::vector<std::unique_ptr<arcade::ISprite>> sprt;

    return sprt;
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::CentipedeGame::getSoundsToLoad() const
{
    std::vector<std::pair<std::string, arcade::SoundType>> sounds;

    return sounds;
}

std::vector<arcade::Sound> arcade::CentipedeGame::getSoundsToPlay()
{
    std::vector<Sound> sounds;

    return sounds;
}

const arcade::IMap &arcade::CentipedeGame::getCurrentMap() const
{
    return _map;
}

arcade::IGUI &arcade::CentipedeGame::getGUI()
{
    return _gui;
}

arcade::Vector2s arcade::CentipedeGame::placePlayer(arcade::Map &map)
{
    Vector2s pos;
    size_t height = map.getHeight();
    size_t width = map.getWidth();

    pos.x = std::rand() % width;
    pos.y = height - 1;
    return pos;
}

void arcade::CentipedeGame::updateMap()
{
    std::cerr << "updating reseting" << std::endl;
    _map.resetMapFromLayer(PLAYER);
    std::cerr << "updating player" << std::endl;
    _map.updateLayer(_centipedeKiller, CentipedeLayers::PLAYER);

    std::cerr << "updating mushroom" << std::endl;
    for (Mushroom *mushroom : _mushrooms)
        _map.updateLayer(*mushroom, CentipedeLayers::PLAYER);

    std::cerr << "updating bullet" << std::endl;
    _map.updateLayer(_bullet, CentipedeLayers::BULLET);

    std::cerr << "updating centipede" << std::endl;
    for (Centipede *centipede : _centipedes)
        for (CentipedePart *part : centipede->getBody())
            _map.updateLayer(*part, CentipedeLayers::CENTIPEDE);
    std::cerr << "updating done" << std::endl;
}

const arcade::Map &arcade::CentipedeGame::getMouliMap() const {
    return _map;
}

arcade::CentipedeGame::~CentipedeGame()
{
    for (Mushroom *mush : _mushrooms)
        if (mush)
            delete mush;
}

const arcade::Vector2s &arcade::CentipedeGame::getPlayerpos() const
{
    return _centipedeKiller.getAbs();
}

extern "C" arcade::IGame *getGame()
{
    return (new arcade::CentipedeGame());
}

void printMap(arcade::GetMap *m)
{
    for (int y = 0; y < m->height; ++y)
    {
        for (int x = 0; x < m->width; ++x) {
            std::cerr << (int)m->tile[y * m->width + x];
        }
        std::cerr << std::endl;
    }
}

static void updateMap(arcade::GetMap *map, const arcade::Map& imap)
{
    for (size_t y = 0; y < imap.getHeight(); ++y)
    {
        for (size_t x = 0; x < imap.getWidth(); ++x)
        {
            for (size_t layer = 0; layer < imap.getLayerNb(); ++layer)
            {
                const arcade::Tile &tile = imap.atMouli(layer, x, y);

                map->tile[y * imap.getWidth() + x] = tile.getType();
/*
                if (tile.getType() == arcade::TileType::OTHER)
                {
                    whereAmI->position[0].x = static_cast<uint16_t >(x);
                    whereAmI->position[0].y = static_cast<uint16_t >(y);
                }
*/
                if (tile.getType() != arcade::TileType::EMPTY)
                    break;
            }
        }
    }
}

extern "C" void Play()
{
    arcade::CentipedeGame centipedeGame;
    arcade::Map const& map = centipedeGame.getMouliMap();
    std::vector<arcade::Event> events;
    size_t whereAmISize = sizeof(arcade::WhereAmI) + sizeof(arcade::Position);
    size_t mapSize = sizeof(arcade::GetMap) + (map.getWidth() * map.getHeight() * sizeof(arcade::TileType));
    arcade::WhereAmI *whereAmI = reinterpret_cast<arcade::WhereAmI *>(new char[whereAmISize] {0});
    arcade::GetMap *getMap = reinterpret_cast<arcade::GetMap*>(new char[mapSize] {0});
    arcade::CommandType command;

    whereAmI->lenght = 1;
    whereAmI->type = arcade::CommandType::WHERE_AM_I;
    getMap->height = static_cast<uint16_t>(map.getHeight());
    getMap->width = static_cast<uint16_t>(map.getWidth());
    getMap->type = arcade::CommandType::GET_MAP;
    updateMap(getMap, map);
    while (read(0, &command, sizeof(arcade::CommandType)))
    {
        arcade::Event event;
        std::cerr << (size_t)command << std::endl;
        event.type = arcade::EventType::ET_KEYBOARD;
        event.action = arcade::ActionType::AT_PRESSED;
        switch (command)
        {
            case (arcade::CommandType::WHERE_AM_I) :
                whereAmI->position[0].x = static_cast<uint16_t >(centipedeGame.getPlayerpos().x);
                whereAmI->position[0].y = static_cast<uint16_t >(centipedeGame.getPlayerpos().y);
                write(1, reinterpret_cast<const char *>(whereAmI), whereAmISize);
                break;
            case (arcade::CommandType::GET_MAP) :
                updateMap(getMap, map);
                printMap(getMap);
                write(1, reinterpret_cast<const char *>(getMap), mapSize);
                break;
            case (arcade::CommandType::GO_UP) :
                event.kb_key = arcade::KB_ARROW_UP;
                events.push_back(event);
                centipedeGame.notifyEvent(std::move(events));
                break;
            case (arcade::CommandType::GO_DOWN) :
                event.kb_key = arcade::KB_ARROW_DOWN;
                events.push_back(event);
                centipedeGame.notifyEvent(std::move(events));
                break;
            case (arcade::CommandType::GO_LEFT) :
                event.kb_key = arcade::KB_ARROW_LEFT;
                events.push_back(event);
                centipedeGame.notifyEvent(std::move(events));
                break;
            case (arcade::CommandType::GO_RIGHT) :
                event.kb_key = arcade::KB_ARROW_RIGHT;
                events.push_back(event);
                centipedeGame.notifyEvent(std::move(events));
                break;
            case (arcade::CommandType::GO_FORWARD) :
                events.push_back(event);
                centipedeGame.notifyEvent(std::move(events));
                break;
            case (arcade::CommandType::SHOOT) :
                event.kb_key = arcade::KB_SPACE;
                events.push_back(event);
                centipedeGame.notifyEvent(std::move(events));
                break;
            case (arcade::CommandType::ILLEGAL) :
                break;
            case (arcade::CommandType::PLAY) :
                centipedeGame.process();
                break;
            default:
                break;
        }
    }
    delete [] whereAmI;
    delete [] getMap;
}