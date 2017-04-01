//
// Created by brout_m on 01/04/17.
//

#include "../include/SpriteGenerator.hpp"

size_t arcade::SpriteGenerator::spritesCount() const
{
    return (SpritesCount);
}

std::string arcade::SpriteGenerator::getGraphicPath(size_t pos) const
{
    return Path + Name + std::to_string(pos) + Ext;
}

char arcade::SpriteGenerator::getAscii(size_t pos) const
{
    return Ascii[pos];
}

arcade::SpriteGenerator::SpriteGenerator(std::string const &ascii,
                                         std::string const &path,
                                         std::string const &sprite,
                                         size_t spritesCount,
                                         std::string const &ext) :
        Ascii(ascii),
        Path(path),
        Name(sprite),
        SpritesCount(spritesCount),
        Ext(ext)
{
}