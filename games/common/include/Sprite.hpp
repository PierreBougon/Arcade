//
// Created by brout_m on 01/04/17.
//

#ifndef CPP_ARCADE_SPRITE_HPP
# define CPP_ARCADE_SPRITE_HPP


#include <glob.h>

namespace arcade
{
    class Sprite
    {
    public:
        ~Sprite() {};
        Sprite(size_t id, size_t spriteCount);
        size_t getSpriteId() const;
        size_t getSpriteCount() const;
        size_t advance();

    private:
        size_t Id;
        size_t SpriteCount;
        size_t Index;

    private:
        Sprite& operator=(Sprite const& sprite) = delete;
        Sprite(Sprite const& sprite) = delete;
    };
}

#endif //CPP_ARCADE_SPRITE_HPP
