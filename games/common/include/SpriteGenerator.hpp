//
// Created by brout_m on 01/04/17.
//

#ifndef CPP_ARCADE_SPRITEGENERATOR_HPP
#define CPP_ARCADE_SPRITEGENERATOR_HPP

#include "ISprite.hpp"

namespace arcade
{
    class SpriteGenerator : public ISprite
    {
    public:
        ~SpriteGenerator() {};
        SpriteGenerator(std::string const& ascii,
                        std::string const& path,
                        std::string const& sprite,
                        size_t spritesCount,
                        std::string const& ext);

    public:
        size_t spritesCount() const;
        std::string getGraphicPath(size_t pos) const;
        char getAscii(size_t pos) const;

    private:
        std::string     Ascii;
        std::string     Path;
        std::string     Name;
        size_t          SpritesCount;
        std::string     Ext;
    };
}

#endif //CPP_ARCADE_SPRITEGENERATOR_HPP
