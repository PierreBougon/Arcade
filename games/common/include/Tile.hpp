//
// Created by brout_m on 01/04/17.
//

#ifndef CPP_ARCADE_TILE_HPP
# define CPP_ARCADE_TILE_HPP

# include "ITile.hpp"
# include "IComponent.hpp"

namespace arcade
{
    class Tile : ITile
    {
    public:
        ~Tile() {};
        Tile();
        TileType getType() const;
        TileTypeEvolution getTypeEv() const;
        Color getColor() const;
        bool hasSprite() const;
        size_t getSpriteId() const;
        size_t getSpritePos() const;
        double getShiftX() const;
        double getShiftY() const;

        void setType(TileType type);
        void setTypeEvo(TileTypeEvolution typeEvo);
        void setSpriteId(size_t id);
        void setSpritePos(size_t pos);
        Tile &operator=(IComponent const& component);

    private:
        TileType Type;
        TileTypeEvolution TypeEvo;
        Color _Color;
        bool Sprite;
        size_t SpriteId;
        size_t Pos;
        double ShiftX;
        double ShiftY;
    };
}

#endif //CPP_ARCADE_TILE_HPP
