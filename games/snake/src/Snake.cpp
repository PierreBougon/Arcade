//
// Created by duhieu_b on 03/04/17.
//

#include <memory>
#include "SpriteGenerator.hpp"
#include "PlayerControlSnake.hpp"
#include "DestroyableObject.hpp"
#include "Snake.hpp"

arcade::GameState arcade::Snake::getGameState() const
{
    return state;
}

void arcade::Snake::notifyEvent(std::vector<arcade::Event> &&events)
{
    std::vector<arcade::Event> tmpEvent;

    tmpEvent = std::move(events);
    snakes[0].updatePlayerInput(tmpEvent);
}

void arcade::Snake::notifyNetwork(std::vector<arcade::NetworkPacket> &&)
{
}

std::vector<arcade::NetworkPacket> &&arcade::Snake::getNetworkToSend()
{
    std::vector<arcade::NetworkPacket> tmp;
    return std::move(tmp);
}

void arcade::Snake::process()
{
    if (!cherry.size())
        putFoodInMap();
    snakes[0].move();
    checkDead();
    if (state == GameState::MENU)
        return;
    moveBody();
    checkEat();
    if (!cherry.size())
        feedingSnakes();
    setSprites();
    if (state == GameState::MENU)
        return;
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin(); it != snakes.end() ; ++it)
    {
        gameMap.updateLayer(snakes[0], 1);
    }
    gameMap.updateLayer(cherry[0], 1);
}


std::vector<std::unique_ptr<arcade::ISprite>> arcade::Snake::getSpritesToLoad() const
{
    std::vector<std::unique_ptr<arcade::ISprite>> tmp;

    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "headUp", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "headLeft", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "headRight", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "headDown", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "bodyHori", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "bodyVerti", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "cornerUpLeft", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "cornerUpRight", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "cornerDownLeft", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "cornerDownRight", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "tailUp", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "tailLeft", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "tailRight", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./assets/img/", "tailDown", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("Y", "./assets/img/", "food", 1, ".png"));
    return tmp;
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::Snake::getSoundsToLoad() const
{
    std::vector<std::pair<std::string, arcade::SoundType>> tmp;
    return tmp;
}

std::vector<arcade::Sound> arcade::Snake::getSoundsToPlay()
{
    std::vector<arcade::Sound> tmp;
   return tmp;
}

const arcade::IMap &arcade::Snake::getCurrentMap() const
{
    return gameMap;
}

const arcade::IGUI &arcade::Snake::getGUI() const
{
    return gameGui;
}

arcade::Snake::Snake() : gameMap("./assets/map.txt", 2)
{
    state = LOADING;
    sprites = getSpritesToLoad();
    createPlayer();
    putFoodInMap();
    state = INGAME;
}

void arcade::Snake::createPlayer()
{
    Vector2s pos;
    size_t y = gameMap.getHeight() / 2;
    size_t x = (gameMap.getWidth() / 2) - 2;
    std::vector<size_t> head = {0, 1, 2, 3};
    std::vector<size_t> tail = {10, 11, 12, 13};
    std::vector<size_t> body = {4, 5};
    std::vector<size_t> count = {1, 1, 1, 1};
    std::vector<size_t> countBody = {1, 1};

    pos.x = x;
    pos.y = y;
    snakes.push_back(PlayerControlSnake(pos, head, count, Orientation::LEFT));
    for (int i = 1; i < 4; ++i)
    {
        pos.x = x + i;
        if (i == 3)
            snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::LEFT));
        else
            snakes.push_back(PlayerControlSnake(pos, body, countBody, Orientation::RIGHT));
    }
}

bool arcade::Snake::checkInSnake(Vector2s const& pos)
{
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin(); it != snakes.end() ; ++it)
    {
        if ((*it).getAbs() == pos)
            return true;
    }
    return false;
}

void arcade::Snake::putFoodInMap()
{
    Vector2s pos;
    std::vector<size_t> food = {14};
    std::vector<size_t> count = {1};

    pos.x = rand() % gameMap.getWidth();
    pos.y = rand() % gameMap.getHeight();
    while (checkInSnake(pos))
    {
        pos.x = rand() % gameMap.getWidth();
        pos.y = rand() % gameMap.getHeight();
    }
    cherry.push_back(DestroyableObject(pos, food, count, Orientation::UP));
}

void arcade::Snake::checkEat()
{
    if (snakes[0].getAbs() == cherry[0].getAbs())
    {
        cherry.erase(cherry.begin());
    }
}

void arcade::Snake::feedingSnakes()
{
    Vector2s pos;
    std::vector<size_t> tail = {10, 11, 12, 13};
    std::vector<size_t> count = {1, 1, 1, 1};

    pos.x = snakes.back().getAbs().x + 1;
    pos.y = snakes.back().getAbs().y;
    if (pos.x <= gameMap.getWidth() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::LEFT));
        return;
    }
    pos.x -= 2;
    if (pos.x <= gameMap.getWidth() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::RIGHT));
        return;
    }
    pos.x += 1;
    pos.y += 1;
    if (pos.y <= gameMap.getHeight() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::DOWN));
        return;
    }
    pos.y -= 2;
    if (pos.y <= gameMap.getHeight() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::UP));
        return;
    }
    state = GameState::MENU;
}

void arcade::Snake::moveBody()
{
    Vector2s pos;
    Vector2s newPos;

    pos = snakes[0].getPrev();
    newPos = pos;
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin() + 1; it != snakes.end() ; ++it)
    {
        newPos = (*it).getAbs();
        (*it).setAbs(pos);
        pos = newPos;
    }
}

void arcade::Snake::checkDead()
{
    Vector2s pos = snakes[0].getAbs();

    if (pos.x > gameMap.getWidth() || pos.y > gameMap.getHeight())
    {
        state = GameState::MENU;
        return;
    }
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin() + 1; it != snakes.end(); ++it)
    {
        if ((*it).getAbs() == pos)
        {
            state = GameState::MENU;
            break;
        }
    }
}

const arcade::Map &arcade::Snake::getMouliMap() const
{
    return gameMap;
}

size_t arcade::Snake::getSizeSnake() const
{
    return snakes.size();
}

arcade::IGUI &arcade::Snake::getGUI()
{
    return gameGui;
}

arcade::tick_t arcade::Snake::getTickRate() const
{
    return 60;
}

std::vector<arcade::Vector2s> arcade::Snake::getPlayerpos()
{
    std::vector<Vector2s> pos;

    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin(); it != snakes.end(); it++)
    {
        pos.push_back((*it).getAbs());
    }
    return pos;
}

void arcade::Snake::setSprites()
{
    Vector2s pos;
    Vector2s posPrev;
    Vector2s posNext;
    std::vector<size_t> body = {4, 5};
    std::vector<size_t> corner = {6, 7, 8, 9};
    std::vector<size_t> count = {1, 1, 1, 1};
    std::vector<size_t> countBody = {1, 1};

    if (snakes[0].getAbs().x > snakes[1].getAbs().x)
        snakes[0].setNewDir(Orientation::RIGHT);
    else if (snakes[0].getAbs().x < snakes[1].getAbs().x)
        snakes[0].setNewDir(Orientation::LEFT);
    else if (snakes[0].getAbs().y > snakes[1].getAbs().y)
        snakes[0].setNewDir(Orientation::DOWN);
    else
        snakes[0].setNewDir(Orientation::UP);
    for (size_t i = 1; i < snakes.size() - 1; i++)
    {
        pos = snakes[i].getAbs();
        posPrev = snakes[i - 1].getAbs();
        posNext = snakes[i + 1].getAbs();
        if (pos.x == posPrev.x && pos.y < posPrev.y && pos.x < posNext.x)
            snakes[i].setSprite(corner, count, Orientation::UP);
        else if (pos.x == posPrev.x && pos.y < posPrev.y && pos.x > posNext.x)
            snakes[i].setSprite(corner, count, Orientation::RIGHT);
        else if (pos.x > posPrev.x && pos.y == posPrev.y && pos.y > posNext.y)
            snakes[i].setSprite(corner, count, Orientation::LEFT);
        else if (pos.x < posPrev.x && pos.y == posPrev.y && pos.y > posNext.y)
            snakes[i].setSprite(corner, count, Orientation::DOWN);
        else if (pos.x == posPrev.x && pos.x == posNext.x)
            snakes[i].setSprite(body, countBody, Orientation::UP);
        else if (pos.y == posPrev.y && pos.y == posNext.y)
            snakes[i].setSprite(body, countBody, Orientation::RIGHT);
    }
    pos = snakes[snakes.size() - 1].getAbs();
    posPrev = snakes[snakes.size() - 2].getAbs();
    if (pos.x == posPrev.x && pos.y > posPrev.y)
        snakes[snakes.size() - 1].setNewDir(Orientation::UP);
    else if (pos.x == posPrev.x && pos.y < posPrev.y)
        snakes[snakes.size() - 1].setNewDir(Orientation::DOWN);
    else if (pos.y == posPrev.y && pos.x > posPrev.x)
        snakes[snakes.size() - 1].setNewDir(Orientation::LEFT);
    else if (pos.y == posPrev.y && pos.x < posPrev.x)
        snakes[snakes.size() - 1].setNewDir(Orientation::RIGHT);
}

extern "C" arcade::IGame *getGame()
{
    return (new arcade::Snake());
}

extern "C" void updateMap(arcade::GetMap *map, const arcade::Map& imap)
{
    for (size_t y = 0; y < imap.getHeight(); ++y)
    {
        for (size_t x = 0; x < imap.getWidth(); ++x)
        {
            for (size_t layer = 0; layer < imap.getLayerNb(); ++layer)
            {
                const arcade::Tile &tile = imap.atMouli(layer, x, y);

                map->tile[y * imap.getWidth() + x] = tile.getType();
                if (tile.getType() != arcade::TileType::EMPTY)
                    break;
            }
        }
    }
}

extern "C" void Play()
{
    arcade::Snake gam;
    arcade::Map const& map = gam.getMouliMap();
    size_t size = 4;
    size_t whereAmISize = sizeof(arcade::WhereAmI) + sizeof(arcade::Position) * size;
    size_t mapSize = sizeof(arcade::GetMap) + (map.getWidth() * map.getHeight() * sizeof(arcade::TileType));
    struct arcade::WhereAmI *player = reinterpret_cast<arcade::WhereAmI *>(new char[whereAmISize] {0});
    struct arcade::GetMap *maps = reinterpret_cast<arcade::GetMap *>(new char[mapSize] {0});
    std::vector<arcade::Event> events;
    std::vector<arcade::Vector2s> pos;
    arcade::CommandType command;

    player->lenght = static_cast<uint16_t >(size);
    player->type = arcade::CommandType::WHERE_AM_I;
    maps->height = static_cast<uint16_t>(map.getHeight());
    maps->width = static_cast<uint16_t>(map.getWidth());
    maps->type = arcade::CommandType::GET_MAP;
    updateMap(maps, map);
    while (std::cin.read(reinterpret_cast<char *>(&command), sizeof(arcade::CommandType)))
    {
        arcade::Event event;
        event.type = arcade::ET_KEYBOARD;
        event.action = arcade::AT_PRESSED;
        maps->type = command;
        std::cerr << "Command: " << static_cast<int>(command) << std::endl;
        switch (command)
        {
            case arcade::CommandType::WHERE_AM_I:
            pos = gam.getPlayerpos();
                player->lenght = static_cast<uint16_t >(pos.size());
                for (size_t i = 0; i < pos.size(); i++)
                {
                    player->position[i].x = static_cast<uint16_t >(pos[i].x);
                    player->position[i].y = static_cast<uint16_t >(pos[i].y);
                }
            std::cout.write(reinterpret_cast<const char *>(player), whereAmISize);
                break;
            case arcade::CommandType::GET_MAP:

            std::cout.write(reinterpret_cast<const char *>(maps), mapSize);
                break;
            case arcade::CommandType::GO_UP:
                event.kb_key = arcade::KB_Z;
                events.push_back(event);
                gam.notifyEvent(std::move(events));
                break;
            case arcade::CommandType::GO_DOWN:
                event.kb_key = arcade::KB_S;
                events.push_back(event);
                gam.notifyEvent(std::move(events));
                break;
            case arcade::CommandType::GO_LEFT:
                event.kb_key = arcade::KB_Q;
                events.push_back(event);
                gam.notifyEvent(std::move(events));
                break;
            case arcade::CommandType::GO_RIGHT:
                event.kb_key = arcade::KB_D;
                events.push_back(event);
                gam.notifyEvent(std::move(events));
                break;
            case arcade::CommandType::GO_FORWARD:
                events.push_back(event);
                gam.notifyEvent(std::move(events));
                break;
            case arcade::CommandType::SHOOT:
                break;
            case arcade::CommandType::ILLEGAL:
                break;
            case arcade::CommandType::PLAY:
                gam.process();
                updateMap(maps, map);
                if (gam.getSizeSnake() > size)
                {
                    size = gam.getGameState();
                    delete [] player;
                    whereAmISize = sizeof(arcade::WhereAmI) + sizeof(arcade::Position) * size;
                    player->lenght = static_cast<uint16_t >(size);
                    player = reinterpret_cast<arcade::WhereAmI *>(new char[whereAmISize]);
                }
                break;
        }
        if (gam.getGameState() == arcade::GameState::MENU)
            break;
    }
}