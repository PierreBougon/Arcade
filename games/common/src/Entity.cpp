//
// Created by duhieu_b on 01/04/17.
//

#include "Entity.hpp"

arcade::Entity::Entity(const arcade::Vector2i &pos, size_t id, size_t spriteCount) : abs(pos), shift({0, 0}), prev(pos), sprite(Sprite(id, spriteCount))
{
}

const arcade::Vector2i &arcade::Entity::getAbs() const
{
    return abs;
}

const arcade::Vector2d &arcade::Entity::getShift() const
{
    return shift;
}

const arcade::Vector2i &arcade::Entity::getPrev() const
{
    return prev;
}

size_t arcade::Entity::advance()
{
    return sprite.advance();
}

size_t arcade::Entity::getSpriteId() const
{
    return sprite.getSpriteId();
}

arcade::TileType arcade::Entity::getType() const {
    return type;
}

arcade::TileTypeEvolution arcade::Entity::getTypeEvo() const {
    return typeEvo;
}
