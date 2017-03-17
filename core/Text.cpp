//
// Created by duhieu_b on 17/03/17.
//

#include "Text.hpp"

arcade::Text::~Text()
{
}

arcade::Text::Text() : value(""), font(""), sprites("")
{
    pos.first = 0;
    pos.second = 0;
    scale = 1;
    type = arcade::TEXT;
}

const std::string &arcade::Text::getValue() const
{
    return value;
}

void arcade::Text::setValue(const std::string &value)
{
    arcade::Text::value = value;
}

const std::string &arcade::Text::getFont() const
{
    return font;
}

void arcade::Text::setFont(const std::string &font)
{
    arcade::Text::font = font;
}

const std::string &arcade::Text::getSprites() const
{
    return sprites;
}

void arcade::Text::setSprites(const std::string &sprites)
{
    arcade::Text::sprites = sprites;
}

const std::pair<int, int> &arcade::Text::getPos() const
{
    return pos;
}

void arcade::Text::setPos(const std::pair<int, int> &pos)
{
    arcade::Text::pos = pos;
}

size_t arcade::Text::getScale() const
{
    return scale;
}

void arcade::Text::setScale(size_t scale)
{
    arcade::Text::scale = scale;
}

arcade::TypeComponent arcade::Text::getType() const
{
    return type;
}
