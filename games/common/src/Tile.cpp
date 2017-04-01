//
// Created by brout_m on 01/04/17.
//

#include "../include/Tile.hpp"

arcade::Tile::Tile() :
    Type(TileType::EMPTY),
    TypeEvo(TileType::EMPTY),
    _Color(arcade::Color::Black),
    Sprite(false),
    SpriteId(0),
    Pos(0),
    ShiftX(0),
    ShiftY(0)
{

}

arcade::TileType arcade::Tile::getType() const
{
    return Type;
}

arcade::TileTypeEvolution arcade::Tile::getTypeEv() const
{
    return TypeEvo;
}

arcade::Color arcade::Tile::getColor() const
{
    return _Color;
}

bool arcade::Tile::hasSprite() const
{
    return Sprite;
}

size_t arcade::Tile::getSpriteId() const
{
    return SpriteId;
}

size_t arcade::Tile::getSpritePos() const
{
    return Pos;
}

double arcade::Tile::getShiftX() const
{
    return ShiftX;
}

double arcade::Tile::getShiftY() const
{
    return ShiftY;
}

void arcade::Tile::setType(arcade::TileType type)
{
    Type = type;
}

void arcade::Tile::setTypeEvo(arcade::TileTypeEvolution typeEvo)
{
    TypeEvo = typeEvo;
}

void arcade::Tile::setSpriteId(size_t id)
{
    SpriteId = id;
}

void arcade::Tile::setSpritePos(size_t pos)
{
    Pos = pos;
}

arcade::Tile &arcade::Tile::operator=(const arcade::IComponent &component)
{
    component.
    return *this;
}

