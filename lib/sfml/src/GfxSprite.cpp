//
// Created by Pierre Bougon on 02/04/17.
//

#include "GfxSprite.hpp"

arcade::GfxSprite::GfxSprite(const std::string &path) : path(path), corrupted(false)
{
    if (!texture.loadFromFile(path))
    {
        corrupted = true;
        return ;
    }
    sprite.setTexture(texture);
}
