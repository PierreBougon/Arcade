//
// Created by brout_m on 03/04/17.
//

#include <map>
#include <algorithm>
#include <iostream>
#include "Vector2.hpp"
#include "Protocol.hpp"
#include "GameState.hpp"
#include "Color.hpp"
#include "CentipedeKiller.hpp"

arcade::CentipedeKiller::CentipedeKiller(Vector2s pos,
                                         std::vector<size_t> idSprite,
                                         std::vector<size_t> spriteCount,
                                         TileType type,
                                         TileTypeEvolution typeEvo,
                                         Color col,
                                         size_t hp) :
        ALivingEntity(pos, idSprite, spriteCount, Orientation::UP, type, typeEvo, col, hp, true),
        _action(KillerAction::NOTHING),
        _move(KillerMove::STAY)
{
}

arcade::CentipedeKiller::CentipedeKiller(arcade::Vector2s pos,
                                         arcade::TileType type,
                                         arcade::TileTypeEvolution typeEvolution,
                                         Color col,
                                         size_t hp) :
        ALivingEntity(pos, type, typeEvolution, col, hp, true),
        _action(KillerAction::NOTHING),
        _move(KillerMove::STAY)
{

}

void arcade::CentipedeKiller::action(arcade::Bullet &bullet)
{
    if (_action == KillerAction::FIRE)
        tryFire(bullet);
    if (bullet.isAlive())
        bullet.go();
    _action = KillerAction::NOTHING;
}

void arcade::CentipedeKiller::move(const arcade::Map &map, const std::list<arcade::Mushroom*> &mushrooms)
{
    static const std::vector<try_move_t > tryMoveTab = {
            &CentipedeKiller::tryMoveTop,
            &CentipedeKiller::tryMoveRight,
            &CentipedeKiller::tryMoveBot,
            &CentipedeKiller::tryMoveLeft
    };

    if (_move != KillerMove::STAY)
    {
        (this->*tryMoveTab[_move])(map, mushrooms);
        _move = KillerMove::STAY;
    }
}

void arcade::CentipedeKiller::updatePlayerInput(std::vector<arcade::Event> &events)
{
    static const std::map<KillerMove, move_t > moveTab = {
            {KillerMove::GO_UP, &CentipedeKiller::isMoveTop},
            {KillerMove::GO_RIGHT, &CentipedeKiller::isMoveRight},
            {KillerMove::GO_DOWN, &CentipedeKiller::isMoveDown},
            {KillerMove::GO_LEFT, &CentipedeKiller::isMoveLeft}
    };
    static const std::map<KillerAction, move_t > actionTab = {
            {KillerAction::FIRE, &CentipedeKiller::isFire}
    };

    for (const arcade::Event &event : events)
    {
        for (const std::pair<KillerMove, move_t> check : moveTab)
        {
            if ((this->*(check.second))(event))
                _move = check.first;
        }

        for (const std::pair<KillerAction, move_t> check : actionTab)
        {
            if ((this->*(check.second))(event))
                _action = check.first;
        }
    }
}

bool arcade::CentipedeKiller::isMoveTop(const arcade::Event &event) const
{
    return event.type == ET_KEYBOARD && event.action == AT_PRESSED &&
           (event.kb_key == KB_Z || event.kb_key == KB_ARROW_UP);
}

bool arcade::CentipedeKiller::isMoveRight(const arcade::Event &event) const
{
    return event.type == ET_KEYBOARD && event.action == AT_PRESSED &&
           (event.kb_key == KB_D || event.kb_key == KB_ARROW_RIGHT);
}

bool arcade::CentipedeKiller::isMoveLeft(const arcade::Event &event) const
{
    return event.type == ET_KEYBOARD && event.action == AT_PRESSED &&
           (event.kb_key == KB_Q || event.kb_key == KB_ARROW_LEFT);
}

bool arcade::CentipedeKiller::isMoveDown(const arcade::Event &event) const
{
    return event.type == ET_KEYBOARD && event.action == AT_PRESSED &&
           (event.kb_key == KB_S || event.kb_key == KB_ARROW_DOWN);
}

bool arcade::CentipedeKiller::isFire(const arcade::Event &event) const
{
    return (event.type == ET_KEYBOARD && event.action == AT_PRESSED &&
            event.kb_key == KB_SPACE) ||
           (event.type == ET_MOUSE && event.action == AT_PRESSED &&
            (event.m_key == M_LEFT_CLICK));
}

void arcade::CentipedeKiller::tryMoveTop(const arcade::Map &map,
                                         const std::list<arcade::Mushroom*> &mushrooms)
{
    Vector2s vec(abs.x, abs.y - 1);

    if (abs.y > static_cast<size_t >(static_cast<double>(map.getHeight()) * 0.8) &&
        static_cast<const Tile&>(map.at(0, abs.x, abs.y - 1)).getType() == TileType::EMPTY &&
        std::find_if(mushrooms.cbegin(), mushrooms.cend(),
                     [&vec](const Mushroom *entity)
                     {
                         return (entity->getAbs() == vec);
                     }) == mushrooms.cend())
        --abs.y;
}

void arcade::CentipedeKiller::tryMoveRight(const arcade::Map &map,
                                           const std::list<arcade::Mushroom*> &mushrooms)
{
    Vector2s vec(abs.x + 1, abs.y);

    if (abs.x < map.getWidth() - 1 &&
        static_cast<const Tile&>(map.at(0, abs.x + 1, abs.y)).getType() == TileType::EMPTY &&
        std::find_if(mushrooms.cbegin(), mushrooms.cend(),
                     [&vec](const Mushroom *entity)
                     {
                         return (entity->getAbs() == vec);
                     }) == mushrooms.cend())
        ++abs.x;
}

void arcade::CentipedeKiller::tryMoveLeft(const arcade::Map &map,
                                          const std::list<arcade::Mushroom*> &mushrooms)
{
    Vector2s vec(abs.x - 1, abs.y);

    if (abs.x > 0 &&
        static_cast<const Tile&>(map.at(0, abs.x - 1, abs.y)).getType() == TileType::EMPTY &&
        std::find_if(mushrooms.cbegin(), mushrooms.cend(),
                     [&vec](const Mushroom *entity)
                     {
                         return (entity->getAbs() == vec);
                     }) == mushrooms.cend())
        --abs.x;
}

void arcade::CentipedeKiller::tryMoveBot(const arcade::Map &map,
                                         const std::list<arcade::Mushroom*> &mushrooms)
{
    Vector2s vec(abs.x, abs.y + 1);

    if (abs.y < map.getHeight() - 1 &&
        static_cast<const Tile&>(map.at(0, abs.x, abs.y + 1)).getType() == TileType::EMPTY &&
        std::find_if(mushrooms.cbegin(), mushrooms.cend(),
                     [&vec](const Mushroom *entity)
                     {
                         return (entity->getAbs() == vec);
                     }) == mushrooms.cend())
        ++abs.y;
}

void arcade::CentipedeKiller::tryFire(arcade::Bullet &bullet)
{
    Vector2s vec(abs.x, abs.y);

    if (!bullet.isAlive())
        bullet.reset(vec);
}

bool arcade::CentipedeKiller::touched(std::list<arcade::Centipede> &centipedes)
{
    for (Centipede &centipede : centipedes)
    {
        for (CentipedePart &part : centipede.getBody())
        {
            if (part.getAbs() == abs)
            {
                if (hp)
                    --hp;
            }
        }
        if (!hp)
            break;
    }
    return (!hp);
}

void arcade::CentipedeKiller::move()
{
}

void arcade::CentipedeKiller::action()
{
}
