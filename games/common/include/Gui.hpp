//
// Created by duhieu_b on 17/03/17.
//

#ifndef CPP_ARCADE_GUI_HPP
#define CPP_ARCADE_GUI_HPP

#include <iostream>
#include <map>
#include <bits/unique_ptr.h>
#include "Factory.hpp"
#include "IComponent.hpp"
#include "GameState.hpp"
#include "IGUI.hpp"

namespace arcade
{
    class Component : public arcade::IComponent
    {
    public:
        Component(double x,
                  double y,
                  double width,
                  double height,
                  size_t spriteId,
                  Color bg,
                  std::string const& txt,
                  Color txtColor);
        Component(double x,
                  double y,
                  double width,
                  double height,
                  Color bg,
                  std::string const& txt,
                  Color txtColor);
        Component(Component const& cmp);

        double getX() const;
        double getY() const;
        double getWidth() const;
        double getHeight() const;
        bool hasSprite() const;
        size_t getBackgroundId() const;
        Color getBackgroundColor() const;
        const std::string &getText() const;
        void setText(std::string text);
        void setSprite(size_t id);
        void setClicked();
        Color getTextColor() const;

    private:
        double _x;
        double _y;
        double _width;
        double _height;
        bool _hasSprite;
        size_t _spriteId;
        Color _color;
        std::string _text;
        Color _textColor;
        bool _clicked;
    };

    class Gui : public arcade::IGUI
    {
    public:
        ~Gui();
        Gui();
        size_t size() const;
        IComponent &at(std::size_t n);
        void addComponent(Component &add);
        void addComponent(Component &&add);

    private:
        std::vector<IComponent *> components;
    };
}

#endif //CPP_ARCADE_GUI_HPP
