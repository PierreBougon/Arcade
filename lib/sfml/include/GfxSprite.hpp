//
// Created by Pierre Bougon on 02/04/17.
//

#ifndef CPP_ARCADE_GFXSPRITE_HPP_
#define CPP_ARCADE_GFXSPRITE_HPP_


#include <cstddef>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace arcade
{
    struct GfxSprite
    {
    private:
        std::string     path;

    public:
        sf::Texture     texture;
        sf::Sprite      sprite;
        bool            corrupted;

        GfxSprite(const std::string &path);
    };
}

#endif // !CPP_ARCADE_GFXSPRITE_HPP_
