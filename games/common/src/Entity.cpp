//
// Created by duhieu_b on 01/04/17.
//

#include "Entity.hpp"

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

arcade::Entity::Entity() : abs({0, 0}), shift({0, 0}), prev({0, 0}), sprite(0, 0)
{
}

arcade::Entity::Entity(arcade::Entity const& cpy) :
        abs(cpy.getAbs()), shift(cpy.getShift()), prev(cpy.getPrev()), sprite(cpy.getSpriteId(), cpy.getSpriteCount()), type(cpy.getType()), typeEvolution(cpy.getTypeEvolution()), color(getColor())
{
}

size_t arcade::Entity::getSpriteCount() const
{
    return sprite.getSpriteCount();
}

arcade::Entity::Entity(const arcade::Vector2i &pos,
                       size_t id,
                       size_t spriteCount,
                       arcade::TileType Type,
                       arcade::TileTypeEvolution TypeEvolution,
                       arcade::Color col) :
    abs(pos),
    shift({0, 0}),
    prev(pos),
    type(Type),
    typeEvolution(TypeEvolution),
    color(col),
    spriteSet(true),
    sprite(id, spriteCount)
{

}

arcade::Entity::Entity(const arcade::Vector2i &pos,
                       arcade::TileType Type,
                       arcade::TileTypeEvolution TypeEvolution,
                       arcade::Color col) :
    abs(pos),
    shift({0, 0}),
    prev(pos),
    type(Type),
    typeEvolution(TypeEvolution),
    color(col),
    spriteSet(false)
{

}


arcade::TileType arcade::Entity::getType() const
{
    return type;
}

arcade::TileTypeEvolution arcade::Entity::getTypeEvolution() const
{
    return typeEvolution;
}

const arcade::Color &arcade::Entity::getColor() const
{
    return color;
}

void arcade::Entity::setType(arcade::TileType Type)
{
    type = Type;
}

void arcade::Entity::setTypeEvolution(arcade::TileTypeEvolution TypeEvolution)
{
    typeEvolution = TypeEvolution;
}

void arcade::Entity::setColor(const arcade::Color &Color)
{
    color = Color;
}

void arcade::Entity::setAbs(const arcade::Vector2i &Abs)
{
    abs = Abs;
}

void arcade::Entity::setShift(const arcade::Vector2d &Shift)
{
    shift = Shift;
}

void arcade::Entity::setPrev(const arcade::Vector2i &Prev)
{
    prev = Prev;
}

bool arcade::Entity::hasSprite() const
{
    return spriteSet;
}

void arcade::Entity::setSprite(size_t id, size_t spriteCount, size_t index)
{
    sprite.setSprite(id, spriteCount, index);
    spriteSet = true;
}

void arcade::Entity::unSetSprite()
{
    spriteSet = false;
}
