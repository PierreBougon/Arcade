//
// Created by brout_m on 01/04/17.
//

#include "../include/Sprite.hpp"

arcade::Sprite::Sprite(size_t id, size_t spriteCount) :
    Id(id),
    SpriteCount(spriteCount),
    Index(0)
{
}

arcade::Sprite::Sprite() :
    Id(0),
    SpriteCount(0),
    Index(0)
{
}

size_t arcade::Sprite::advance()
{
    size_t tmp;

    tmp = Index;
    if (Index == SpriteCount - 1)
        Index = 0;
    else
        ++Index;
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
