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

arcade::CentipedeKiller::CentipedeKiller(Vector2ui pos,
                                         size_t idSprite,
                                         size_t spriteCount,
                                         TileType type,
                                         TileTypeEvolution typeEvo,
                                         Color col,
                                         size_t hp,
                                         const Map &map,
                                         const std::vector<Entity> &entities) :
        ALivingEntity(pos, idSprite, spriteCount, type, typeEvo, col, hp, true),
        _action(KillerAction::NOTHING),
        _move(KillerMove::STAY),
        _map(map),
        _entities(entities)
{

}

arcade::CentipedeKiller::CentipedeKiller(arcade::Vector2ui pos,
                                         arcade::TileType type,
                                         arcade::TileTypeEvolution typeEvolution,
                                         Color col,
                                         size_t hp,
                                         const Map &map,
                                         const std::vector<Entity> &entities) :
        ALivingEntity(pos, type, typeEvolution, col, hp, true),
        _action(KillerAction::NOTHING),
        _move(KillerMove::STAY),
        _map(map),
        _entities(entities)
{

}

void arcade::CentipedeKiller::action()
{

}

void arcade::CentipedeKiller::move()
{

}

void arcade::CentipedeKiller::updatePlayerInput(const std::vector<arcade::Event> &events)
{
    static std::map<KillerMove, move_t > moveTab = {
            {KillerMove::GO_UP, &isMoveTop},
            {KillerMove::GO_RIGHT, &isMoveRight},
            {KillerMove::GO_DOWN, &isMoveDown},
            {KillerMove::GO_LEFT, &isMoveLeft}
    };
    static std::map<KillerAction, move_t > actionTab = {
            {KillerAction::FIRE, &isFire}
    };

    _move = KillerMove::STAY;
    _action = KillerAction::NOTHING;
    for (const arcade::Event &event : events)
    {
        for (std::pair<KillerMove, move_t> check : moveTab)
        {
            if ((this->*(check.second))(event))
                _move = check.first;
        }

        for (std::pair<KillerAction, move_t> check : actionTab)
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
    std::vector<Entity>::const_iterator it;

    if (abs.y > static_cast<int>(static_cast<double>(_map.getHeight()) * 0.8) &&
        static_cast<const Tile&>(_map.at(0, abs.y - 1, abs.x)).getType() == TileType::EMPTY)
    {
        it = std::find_if(_entities.cbegin(), _entities.cend(), [*this](const Entity& entity)
                          {
                              return (entity.getAbs() == abs && entity);
                          });
        if ()
            abs.y--;
    }
}

void arcade::CentipedeKiller::tryMoveRight()
{
    if (abs.x < )
}

void arcade::CentipedeKiller::tryMoveLeft()
{
}

void arcade::CentipedeKiller::tryMoveBot()
{
}
