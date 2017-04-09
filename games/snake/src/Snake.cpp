//
// Created by duhieu_b on 03/04/17.
//

#include <memory>
#include <string>
#include "SpriteGenerator.hpp"
#include "PlayerControlSnake.hpp"
#include "DestroyableObject.hpp"
#include "Snake.hpp"
#include "Tick.hpp"

static bool talinette = false;

arcade::GameState arcade::Snake::getGameState() const
{
    return state;
}

void arcade::Snake::notifyEvent(std::vector<arcade::Event> &&events)
{
    std::vector<arcade::Event> tmpEvent;

    if (events.size() > 0 && events[0].action == AT_PRESSED && events[0].type == ET_KEYBOARD &&
        events[0].kb_key == KB_ESCAPE)
    {
        state = MENU;
        tmpEvent = std::move(events);
    }
    else
    {
        tmpEvent = std::move(events);
        snakes[0].updatePlayerInput(tmpEvent);
    }
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
    gameMap.resetMapFromLayer(0);
    if (!cherry.size())
        putFoodInMap();
    moveSnake();
    if (state == GameState::MENU)
        return;


    checkEat();
    if (!cherry.size())
        feedingSnakes();
    setSprites();
    if (state == GameState::MENU)
        return;
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin(); it != snakes.end(); ++it)
    {
        gameMap.updateLayer((*it), 1);
    }
    if (cherry.size())
        gameMap.updateLayer(cherry[0], 1);
    for (size_t i = 0; i < gameMap.getHeight(); ++i)
        for (size_t j = 0; j < gameMap.getWidth(); ++j)
        {
            empty.setAbs({j, i});
            gameMap.updateLayer(empty, 0);
        }
    tick++;
}

std::vector<std::unique_ptr<arcade::ISprite>> arcade::Snake::getSpritesToLoad() const
{
    std::vector<std::unique_ptr<arcade::ISprite>> tmp;

    tmp.push_back(std::make_unique<SpriteGenerator>("A", "./games/snake/assets/img/", "snake_head_up", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>(">", "./games/snake/assets/img/", "snake_head_right", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("v", "./games/snake/assets/img/", "snake_head_down", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("<", "./games/snake/assets/img/", "snake_head_left", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./games/snake/assets/img/", "snake_center_V", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./games/snake/assets/img/", "snake_center_H", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./games/snake/assets/img/", "snake_corner_top_left", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./games/snake/assets/img/", "snake_corner_top_right", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./games/snake/assets/img/", "snake_corner_down_left", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("O", "./games/snake/assets/img/", "snake_corner_down_right", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("u", "./games/snake/assets/img/", "snake_tail_up", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("<", "./games/snake/assets/img/", "snake_tail_right", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("^", "./games/snake/assets/img/", "snake_tail_down", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>(">", "./games/snake/assets/img/", "snake_tail_left", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("@", "./games/snake/assets/img/", "apple", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>(" ", "./games/snake/assets/img/", "floor", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("Score", "./games/snake/assets/img/", "score", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("0", "./games/snake/assets/img/", "zero", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("1", "./games/snake/assets/img/", "one", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("2", "./games/snake/assets/img/", "two", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("3", "./games/snake/assets/img/", "three", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("4", "./games/snake/assets/img/", "four", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("5", "./games/snake/assets/img/", "five", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("6", "./games/snake/assets/img/", "six", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("7", "./games/snake/assets/img/", "seven", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("8", "./games/snake/assets/img/", "eight", 1, ".png"));
    tmp.push_back(std::make_unique<SpriteGenerator>("9", "./games/snake/assets/img/", "nine", 1, ".png"));
    return std::move(tmp);
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

arcade::Snake::Snake() :
        gameMap("./assets/map.txt", 2),
        empty(Entity({0, 0},
                     std::vector<size_t>({15}),
                     std::vector<size_t>({1}),
                     Orientation::UP,
                     TileType::EMPTY,
                     TileTypeEvolution::EMPTY,
                     Color::Black,
                     false)),
        tick(0),
        score(Score()),
        snakeSpeed(4)
{
    state = LOADING;
    createPlayer();
    putFoodInMap();
    settingScore();
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
    snakes[0].setColor(Color(Color::Green));
    for (int i = 1; i < 4; ++i)
    {
        pos.x = x + i;
        if (i == 3)
        {
            snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::LEFT));
            snakes[i].setColor(Color(Color::Yellow));
        }
        else
        {
            snakes.push_back(PlayerControlSnake(pos, body, countBody, Orientation::RIGHT));
            snakes[i].setColor(Color(Color::Cyan));
        }
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
    cherry[0].setColor(Color(Color::White));
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

    score.setScore(score.getScore() + 1);
    static_cast<Component&>(gameGui.at(0)).setText("Score : " + std::to_string(score.getScore()));
    for (size_t posi = 0; posi < score.getPos().size(); ++posi)
    {
        static_cast<Component&>(gameGui.at(posi + 1)).setSprite(score.getSpiteId()[posi][score.getPos()[posi]]);
    }

    pos.x = snakes.back().getAbs().x + 1;
    pos.y = snakes.back().getAbs().y;
    if (pos.x < gameMap.getWidth() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::LEFT));
        snakes[snakes.size() - 1].setColor(Color(Color::Yellow));
        return;
    }
    pos.x -= 2;
    if (pos.x < gameMap.getWidth() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::RIGHT));
        snakes[snakes.size() - 1].setColor(Color(Color::Yellow));
        return;
    }
    pos.x += 1;
    pos.y += 1;
    if (pos.y < gameMap.getHeight() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::DOWN));
        snakes[snakes.size() - 1].setColor(Color(Color::Yellow));
        return;
    }
    pos.y -= 2;
    if (pos.y < gameMap.getHeight() && !checkInSnake(pos))
    {
        snakes.push_back(PlayerControlSnake(pos, tail, count, Orientation::UP));
        snakes[snakes.size() - 1].setColor(Color(Color::Yellow));
        return;
    }
    state = GameState::MENU;
}

void arcade::Snake::moveSnake()
{
    if (!(tick % (static_cast<size_t>(Tick::BASIC_TICK_RATE) / snakeSpeed)) || talinette)
    {
        snakes[0].move();
        checkDead();
        moveBody(true);
    }
    else
    {
        snakes[0].moveShift(tick % (static_cast<size_t>(Tick::BASIC_TICK_RATE) / snakeSpeed),
                            (static_cast<size_t>(Tick::BASIC_TICK_RATE) / snakeSpeed));
        moveBody(false);
    }
}

void arcade::Snake::moveBody(bool movePhysic)
{
    Vector2s pos;
    Vector2s newPos;
    double   shift;
    Vector2d newShift;

    pos = snakes[0].getPrev();
    shift = snakes[0].getShift().x == 0.0d ? snakes[0].getShift().y : snakes[0].getShift().x;
    newPos = pos;
    for (std::vector<PlayerControlSnake>::iterator it = snakes.begin() + 1; it != snakes.end() ; ++it)
    {
        newPos = (*it).getAbs();
        if (movePhysic)
            (*it).setAbs(pos);
        switch (it->getOrientation())
        {
            case Orientation::UP :
            case Orientation::DOWN :
                newShift.x = 0; newShift.y = shift;
                break;
            case Orientation::LEFT :
            case Orientation::RIGHT :
                newShift.x = shift; newShift.y = 0;
                break;
            default:
                break;
        }
        it->setShift(newShift);
        pos = newPos;
    }
}

void arcade::Snake::checkDead()
{
    Vector2s pos = snakes[0].getAbs();

    if (pos.x >= gameMap.getWidth() || pos.y >= gameMap.getHeight())
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
    snakes[0].setColor(Color(Color::Green));
    for (size_t i = 1; i < snakes.size() - 1; i++)
    {
        pos = snakes[i].getAbs();
        posPrev = snakes[i - 1].getAbs();
        posNext = snakes[i + 1].getAbs();
        if (pos.x == posPrev.x && pos.y < posPrev.y && pos.x < posNext.x)
        {
            snakes[i].setSprite(corner, count, Orientation::UP);
            snakes[i].setColor(Color(Color::Cyan));
        }
        else if (pos.x == posPrev.x && pos.y < posPrev.y && pos.x > posNext.x)
        {
            snakes[i].setSprite(corner, count, Orientation::RIGHT);
            snakes[i].setColor(Color(Color::Cyan));
        }
        else if (pos.x > posPrev.x && pos.y == posPrev.y && pos.y > posNext.y)
        {
            snakes[i].setSprite(corner, count, Orientation::LEFT);
            snakes[i].setColor(Color(Color::Cyan));
        }
        else if (pos.x < posPrev.x && pos.y == posPrev.y && pos.y > posNext.y)
        {
            snakes[i].setSprite(corner, count, Orientation::DOWN);
            snakes[i].setColor(Color(Color::Cyan));
        }
        else if (pos.x == posPrev.x && pos.x == posNext.x)
        {
            snakes[i].setSprite(body, countBody, Orientation::UP);
            snakes[i].setColor(Color(Color::Cyan));
        }
        else if (pos.y == posPrev.y && pos.y  == posNext.y)
        {
            snakes[i].setSprite(body, countBody, Orientation::RIGHT);
            snakes[i].setColor(Color(Color::Cyan));
        }
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

void arcade::Snake::settingScore()
{
    double i(0.05);

    gameGui.addComponent(Component(0.05, 0.05, 0.1, 0.1, 17, Color::Blue, "Score : " + std::to_string(score.getScore()), Color(1)));
    for (size_t pos = 0; pos < score.getPos().size(); ++pos)
    {
        i += 0.10;
        gameGui.addComponent(Component(i, 0.05, 0.1, 0.1, score.getSpiteId()[pos][score.getPos()[pos]], Color::Blue, "", Color(1)));
    }
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

    talinette = true;
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