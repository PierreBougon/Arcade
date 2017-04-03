//
// Created by brout_m on 03/04/17.
//

#include <map>
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
                                         size_t hp) :
        ALivingEntity(pos, idSprite, spriteCount, type, typeEvo, col, hp)

{

}

arcade::CentipedeKiller::CentipedeKiller(arcade::Vector2ui pos,
                                         arcade::TileType type,
                                         arcade::TileTypeEvolution typeEvolution,
                                         Color col,
                                         size_t hp) :
        ALivingEntity(pos, type, typeEvolution, col, hp)
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
            {KillerMove::GO_RIGHT, &isMoveTop},
            {KillerMove::GO_DOWN, &isMoveTop},
            {KillerMove::GO_LEFT, &isMoveTop}
    };
    static std::map<KillerAction, move_t > actionTab = {
            {KillerAction::FIRE, &isFire}
    };

    _move = KillerMove::STAY;
    for (const arcade::Event &event : events)
    {

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
