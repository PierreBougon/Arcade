//
// Created by Pierre Bougon on 02/04/17.
//

#include "GfxSprite.hpp"

arcade::GfxSprite::GfxSprite(const std::string &path) : path(path)
{
    if (!texture.loadFromFile(path))
        throw std::bad_alloc();
    sprite.setTexture(texture);
}
