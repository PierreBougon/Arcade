//
// Created by brout_m on 01/04/17.
//

#include <iostream>
#include "Tile.hpp"

arcade::Tile::Tile() :
    Type(TileType::EMPTY),
    TypeEvo(TileTypeEvolution::EMPTY),
    _Color(arcade::Color::Transparent),
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

void arcade::Tile::setShiftX(double shift)
{
    ShiftX = shift;
}

void arcade::Tile::setShiftY(double shift)
{
    ShiftY = shift;
}

arcade::Tile &arcade::Tile::operator=(arcade::Entity &entity)
{
    const Vector2d &shift = entity.getShift();

    Type = entity.getType();
    TypeEvo = entity.getTypeEvolution();
    _Color = entity.getColor();
    Sprite = entity.hasSprite();
    if (entity.hasSprite())
    {
        SpriteId = entity.getSpriteId();
        Pos = entity.advance();
    }
    else
    {
        SpriteId = 0;
        Pos = 0;
    }
    ShiftX = shift.x;
    ShiftY = shift.y;
    return *this;
}

arcade::Tile &arcade::Tile::operator=(const arcade::Tile &tile)
{
    Type = tile.Type;
    TypeEvo = tile.TypeEvo;
    _Color = tile._Color;
    Sprite = tile.Sprite;
    SpriteId = tile.SpriteId;
    Pos = tile.Pos;
    ShiftX = tile.ShiftX;
    ShiftY = tile.ShiftY;
    return  *this;
}

arcade::Tile &arcade::Tile::operator<<(arcade::Entity &entity) {
    if (Sprite)
        Pos = entity.advance();
    return *this;
}
