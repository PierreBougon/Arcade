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
        Sprite();
        Sprite(size_t id, size_t spriteCount = 1);
        size_t getSpriteId() const;
        size_t getSpriteCount() const;
        size_t advance();
        void setSprite(size_t id, size_t spriteCount = 1, size_t index = 0);

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
