//
// Created by duhieu_b on 01/04/17.
//

#include "Entity.hpp"

const arcade::Vector2s &arcade::Entity::getAbs() const
{
    return abs;
}

const arcade::Vector2d &arcade::Entity::getShift() const
{
    return shift;
}

const arcade::Vector2s &arcade::Entity::getPrev() const
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

arcade::Entity::Entity(arcade::Entity const& cpy) :
        abs(cpy.getAbs()),
        shift(cpy.getShift()),
        prev(cpy.getPrev()),
        type(cpy.getType()), typeEvolution(cpy.getTypeEvolution()),
        color(getColor()),
        sprite(cpy.getSpriteId(), cpy.getSpriteCount())
{
}

size_t arcade::Entity::getSpriteCount() const
{
    return sprite.getSpriteCount();
}

arcade::Entity::Entity(const arcade::Vector2s &pos,
                       size_t id,
                       size_t spriteCount,
                       arcade::TileType Type,
                       arcade::TileTypeEvolution TypeEvolution,
                       arcade::Color col,
                       bool collide) :
    abs(pos),
    shift({0, 0}),
    prev(pos),
    type(Type),
    typeEvolution(TypeEvolution),
    color(col),
    spriteSet(true),
    collidable(collide),
    sprite(id, spriteCount)
{

}

arcade::Entity::Entity(const arcade::Vector2s &pos,
                       arcade::TileType Type,
                       arcade::TileTypeEvolution TypeEvolution,
                       arcade::Color col,
                       bool collide) :
    abs(pos),
    shift({0, 0}),
    prev(pos),
    type(Type),
    typeEvolution(TypeEvolution),
    color(col),
    spriteSet(false),
    collidable(collide)
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

void arcade::Entity::setAbs(const arcade::Vector2s &Abs)
{
    abs = Abs;
}

void arcade::Entity::setShift(const arcade::Vector2d &Shift)
{
    shift = Shift;
}

void arcade::Entity::setPrev(const arcade::Vector2s &Prev)
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

void arcade::Entity::playAnimation()
{
    sprite.resume();
}

void arcade::Entity::pauseAnimation()
{
    sprite.pause();
}

void arcade::Entity::resetAnimation()
{
    sprite.reset();
}

void arcade::Entity::setAnimationUnique()
{
    sprite.setMode(Sprite::UNIQUE);
}

void arcade::Entity::setAnimationRepeat()
{
    sprite.setMode(Sprite::REPEAT);
}

void arcade::Entity::setAnimationMode(arcade::Sprite::SpriteMode mode)
{
    sprite.setMode(mode);
}