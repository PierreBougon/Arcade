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
        enum SpriteMode
        {
            UNIQUE,
            REPEAT
        };

    public:
        ~Sprite() {};
        Sprite();
        Sprite(size_t id, size_t spriteCount = 1);
        size_t getSpriteId() const;
        size_t getSpriteCount() const;
        size_t advance();
        void pause();
        void resume();
        void reset();
        void setMode(SpriteMode mode);
        void setSprite(size_t id, size_t spriteCount = 1, size_t index = 0);
        Sprite& operator=(Sprite const& sprite);

    private:
        size_t Id;
        size_t SpriteCount;
        size_t Index;
        bool Paused;
        SpriteMode Mode;

    private:
        Sprite(Sprite const& sprite) = delete;
    };
}

#endif //CPP_ARCADE_SPRITE_HPP
