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
    class GfxSprite
    {
    private:
        size_t      id;
        sf::Texture texture;
        sf::Sprite  sprite;

    public:

    };
}

#endif // !CPP_ARCADE_GFXSPRITE_HPP_
