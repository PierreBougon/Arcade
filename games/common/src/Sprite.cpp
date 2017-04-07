//
// Created by brout_m on 01/04/17.
//

#include "Sprite.hpp"

arcade::Sprite::Sprite(size_t id, size_t spriteCount) :
    Id(id),
    SpriteCount(spriteCount),
    Index(0),
    Paused(true)
{
}

arcade::Sprite::Sprite() :
    Id(0),
    SpriteCount(0),
    Index(0),
    Paused(true)
{
}

size_t arcade::Sprite::advance()
{
    size_t tmp;

    if (Paused)
        return (Index);

    tmp = Index;

    if (Index == SpriteCount - 1)
        Index = 0;
    else
        ++Index;

    if (!Index && Mode == Sprite::UNIQUE)
        Paused = true;

    return tmp;
}

size_t arcade::Sprite::getSpriteId() const
{
    return Id;
}

size_t arcade::Sprite::getSpriteCount() const
{
    return SpriteCount;
}

void arcade::Sprite::setSprite(size_t id, size_t spritesCount, size_t index)
{
    Id = id;
    Index = index;
    SpriteCount = spritesCount;
}

void arcade::Sprite::pause()
{
    Paused = true;
}

void arcade::Sprite::resume()
{
    Paused = false;
}

void arcade::Sprite::reset()
{
    Paused = true;
    Index = 0;
}

void arcade::Sprite::setMode(arcade::Sprite::SpriteMode mode)
{
    Mode = mode;
}

arcade::Sprite &arcade::Sprite::operator=(const arcade::Sprite &sprite) {
    Index = sprite.Index;
    Id = sprite.Id;
    SpriteCount = sprite.SpriteCount;
    Paused = sprite.Paused;
    Mode = sprite.Mode;
    return *this;
}

arcade::Sprite::Sprite(const arcade::Sprite &sprite) :
    Id(sprite.Id), SpriteCount(sprite.SpriteCount), Index(sprite.Index), Paused(sprite.Paused), Mode(sprite.Mode)
{

}
