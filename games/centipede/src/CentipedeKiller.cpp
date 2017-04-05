//
// Created by brout_m on 03/04/17.
//

#include <map>
#include <algorithm>
#include "Vector2.hpp"
#include "Protocol.hpp"
#include "GameState.hpp"
#include "Color.hpp"
#include "CentipedeKiller.hpp"

arcade::CentipedeKiller::CentipedeKiller(Vector2s pos,
                                         size_t idSprite,
                                         size_t spriteCount,
                                         TileType type,
                                         TileTypeEvolution typeEvo,
                                         Color col,
                                         size_t hp,
                                         const Map &map,
                                         std::list<Mushroom*> &mushrooms,
                                         std::list<Centipede> &entities,
                                         Bullet &bullet) :
        ALivingEntity(pos, idSprite, spriteCount, type, typeEvo, col, hp, true),
        _action(KillerAction::NOTHING),
        _move(KillerMove::STAY),
        _map(map),
        _mushrooms(mushrooms),
        _centipedes(entities),
        _bullet(bullet)
{

}

arcade::CentipedeKiller::CentipedeKiller(arcade::Vector2s pos,
                                         arcade::TileType type,
                                         arcade::TileTypeEvolution typeEvolution,
                                         Color col,
                                         size_t hp,
                                         const Map &map,
                                         std::list<Mushroom*> &mushrooms,
                                         std::list<Centipede> &entities,
                                         Bullet &bullet) :
        ALivingEntity(pos, type, typeEvolution, col, hp, true),
        _action(KillerAction::NOTHING),
        _move(KillerMove::STAY),
        _map(map),
        _mushrooms(mushrooms),
        _centipedes(entities),
        _bullet(bullet)
{

}

void arcade::CentipedeKiller::action()
{
    tryFire();
    if (_bullet.isAlive())
        _bullet.go();
    _action = KillerAction::NOTHING;
}

void arcade::CentipedeKiller::move()
{
    static const std::vector<try_move_t > tryMoveTab = {
            &CentipedeKiller::tryMoveTop,
            &CentipedeKiller::tryMoveRight,
            &CentipedeKiller::tryMoveBot,
            &CentipedeKiller::tryMoveLeft
    };

    if (_move != KillerMove::STAY)
    {
        (this->*tryMoveTab[_move])();
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

    _move = KillerMove::STAY;
    _action = KillerAction::NOTHING;
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

void arcade::CentipedeKiller::tryMoveTop()
{
    Vector2s vec(abs.x, abs.y - 1);

    if (abs.y > static_cast<int>(static_cast<double>(_map.getHeight()) * 0.8) &&
        static_cast<const Tile&>(_map.at(0, abs.x, abs.y - 1)).getType() == TileType::EMPTY &&
        std::find_if(_mushrooms.cbegin(), _mushrooms.cend(),
                     [&vec](const Mushroom *entity)
                     {
                         return (entity->getAbs() == vec);
                     }) != _mushrooms.cend())
        --abs.y;
}

void arcade::CentipedeKiller::tryMoveRight()
{
    Vector2s vec(abs.x + 1, abs.y);

    if (abs.x < _map.getWidth() - 1 &&
        static_cast<const Tile&>(_map.at(0, abs.x + 1, abs.y)).getType() == TileType::EMPTY &&
        std::find_if(_mushrooms.cbegin(), _mushrooms.cend(),
                     [&vec](const Mushroom *entity)
                     {
                         return (entity->getAbs() == vec);
                     }) != _mushrooms.cend())
        ++abs.x;
}

void arcade::CentipedeKiller::tryMoveLeft()
{
    Vector2s vec(abs.x - 1, abs.y);

    if (abs.x > 0 &&
        static_cast<const Tile&>(_map.at(0, abs.x - 1, abs.y)).getType() == TileType::EMPTY &&
        std::find_if(_mushrooms.cbegin(), _mushrooms.cend(),
                     [&vec](const Mushroom *entity)
                     {
                         return (entity->getAbs() == vec);
                     }) != _mushrooms.cend())
        --abs.x;
}

void arcade::CentipedeKiller::tryMoveBot()
{
    Vector2s vec(abs.x, abs.y + 1);

    if (abs.y < _map.getHeight() - 1 &&
        static_cast<const Tile&>(_map.at(0, abs.x, abs.y + 1)).getType() == TileType::EMPTY &&
        std::find_if(_mushrooms.cbegin(), _mushrooms.cend(),
                     [&vec](const Mushroom *entity)
                     {
                         return (entity->getAbs() == vec);
                     }) != _mushrooms.cend())
        ++abs.y;
}

void arcade::CentipedeKiller::tryFire()
{
    if (!_bullet.isAlive())
        _bullet.reset({abs.y, abs.x});
}

bool arcade::CentipedeKiller::touched()
{
    for (Centipede &centipede : _centipedes)
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