//
// Created by duhieu_b on 03/04/17.
//

#include <PlayerControlSnake.hpp>
#include <DestroyableObject.hpp>
#include "Snake.hpp"

arcade::GameState arcade::Snake::getGameState() const
{
    return state;
}

void arcade::Snake::notifyEvent(std::vector<arcade::Event> &&events)
{
    std::vector<arcade::Event> tmpEvent;

    tmpEvent = events;
    snakes[0].updatePlayerInput(tmpEvent);
}

void arcade::Snake::notifyNetwork(std::vector<arcade::NetworkPacket> &&events)
{
}

std::vector<arcade::NetworkPacket> &&arcade::Snake::getNetworkToSend()
{
    return nullptr;
}

void arcade::Snake::process()
{
    if (!cherry.size())
        putFoodInMap();
    snakes[0].move();
    checkDead();
    if (state == GameState::QUIT)
        return;
    moveBody();
    checkEat();
    if (!cherry.size())
        feedingSnakes();
    if (state == GameState::QUIT)
        return;
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin(); it != snakes.end() ; ++it)
    {
        gameMap.updateLayer(snakes[0], 1);
    }
    gameMap.updateLayer(cherry[0], 1);
}


std::vector<std::unique_ptr<arcade::ISprite>> &&arcade::Snake::getSpritesToLoad() const
{
    return nullptr;
}

std::vector<std::string> arcade::Snake::getSoundsToLoad() const
{
    return nullptr;
}

std::vector<int> &&arcade::Snake::getSoundsToPlay()
{
    return nullptr;
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
    //action = MOVE;
    state = LOADING;
    createPlayer();
    putFoodInMap();
}

void arcade::Snake::createPlayer()
{
    Vector2s pos;
    size_t y = gameMap.getHeight() / 2;
    size_t x = gameMap.getWidth() / 2 - 2;

    pos.x = x;
    pos.y = y;
    snakes.push_back(PlayerControlSnake(pos, TileType::EVIL_DUDE, TileTypeEvolution::PLAYER, Color::Cyan, 1, true));
    for (int i = 1; i < 4; ++i)
    {
        pos.x = x + i;
        snakes.push_back(PlayerControlSnake(pos, TileType::EVIL_DUDE, TileTypeEvolution::PLAYER, Color::Cyan, 1, true));
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

    pos.x = rand() % gameMap.getWidth();
    pos.y = rand() % gameMap.getHeight();
    while (checkInSnake(pos))
    {
        pos.x = rand() % gameMap.getWidth();
        pos.y = rand() % gameMap.getHeight();
    }
    cherry.push_back(DestroyableObject(pos, TileType::OTHER, TileTypeEvolution::FOOD, Color::Red, 1, false));
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

    pos.x = snakes.back().getAbs().x + 1;
    pos.y = snakes.back().getAbs().y;
    if (pos.x <= gameMap.getWidth() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, TileType::EVIL_DUDE, TileTypeEvolution::PLAYER, Color::Cyan, 1, true));
        return;
    }
    pos.x -= 2;
    if (pos.x >= 0 && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, TileType::EVIL_DUDE, TileTypeEvolution::PLAYER, Color::Cyan, 1, true));
        return;
    }
    pos.x += 1;
    pos.y += 1;
    if (pos.y <= gameMap.getHeight() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, TileType::EVIL_DUDE, TileTypeEvolution::PLAYER, Color::Cyan, 1, true));
        return;
    }
    pos.y -= 2;
    if (pos.y >= 0 && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, TileType::EVIL_DUDE, TileTypeEvolution::PLAYER, Color::Cyan, 1, true));
        return;
    }
    state = GameState::QUIT;
}

void arcade::Snake::moveBody()
{
    Vector2s pos;

    pos = snakes[0].getAbs();
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin() + 1; it != snakes.end() ; ++it)
    {
        (*it).setAbs(pos);
        pos = (*it).getAbs();
    }
}

void arcade::Snake::checkDead()
{
    Vector2s pos = snakes[0].getAbs();

    if (pos.x < 0 || pos.x > gameMap.getWidth() || pos.y < 0 || pos.y > gameMap.getHeight())
    {
        state = GameState::QUIT;
        return;
    }
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin() + 1; it != snakes.end(); ++it)
    {
        if ((*it).getAbs() == pos)
        {
            state = GameState::QUIT;
            break;
        }
    }
}
