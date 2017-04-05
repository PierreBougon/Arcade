//
// Created by duhieu_b on 17/03/17.
//

#ifndef CPP_ARCADE_TEXT_HPP
#define CPP_ARCADE_TEXT_HPP

#include <iostream>
#include <GameState.hpp>
#include "IComponent.hpp"
#include "Factory.hpp"

namespace arcade
{
    class Text : public IComponent
    {
    private:
        std::string value;
        std::string font;
        std::string sprites;
        std::pair<int, int> pos;
        size_t scale;
        arcade::TypeComponent type;

    public:
        ~Text();
        Text();
        const std::string &getValue() const;
        void setValue(const std::string &value);
        const std::string &getFont() const;
        TypeComponent getType() const;
        void setFont(const std::string &font);
        const std::string &getSprites() const;
        void setSprites(const std::string &sprites);
        const std::pair<int, int> &getPos() const;
        void setPos(const std::pair<int, int> &pos);
        size_t getScale() const;
        void setScale(size_t scale);
    };
}

#endif //CPP_ARCADE_TEXT_HPP