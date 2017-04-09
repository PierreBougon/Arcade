//
// Created by duhieu_b on 17/03/17.
//

#include "Gui.hpp"

arcade::Gui::~Gui()
{
}

size_t arcade::Gui::size() const
{
    return components.size();
}

arcade::IComponent &arcade::Gui::at(std::size_t n)
{
    size_t counter(0);
    std::vector<IComponent *>::iterator it;

    for (it = components.begin(); it != components.end() ; ++it)
    {
        if (counter == n)
            break;
        counter++;
    }
    return (*(*it));
}

arcade::Gui::Gui()
{

}

void arcade::Gui::addComponent(arcade::Component &add)
{
    components.push_back(new Component(add));
}

void arcade::Gui::addComponent(arcade::Component &&add)
{
    components.push_back(new Component(add));
}


double arcade::Component::getX() const
{
    return _x;
}

double arcade::Component::getY() const
{
    return _y;
}

double arcade::Component::getWidth() const
{
    return _width;
}

double arcade::Component::getHeight() const
{
    return _height;
}

bool arcade::Component::hasSprite() const
{
    return _hasSprite;
}

size_t arcade::Component::getBackgroundId() const
{
    return _spriteId;
}

arcade::Color arcade::Component::getBackgroundColor() const
{
    return _color;
}

const std::string &arcade::Component::getText() const
{
    return _text;
}

void arcade::Component::setClicked()
{
    _clicked = true;
}

arcade::Color arcade::Component::getTextColor() const
{
    return _textColor;
}

arcade::Component::Component(double x,
                             double y,
                             double width,
                             double height,
                             size_t spriteId,
                             arcade::Color bg,
                             std::string const &txt,
                             arcade::Color txtColor) :
        _x(x),
        _y(y),
        _width(width),
        _height(height),
        _hasSprite(true),
        _spriteId(spriteId),
        _color(bg),
        _text(txt),
        _textColor(txtColor),
        _clicked(false)
{
}

arcade::Component::Component(double x,
                             double y,
                             double width,
                             double height,
                             arcade::Color bg,
                             std::string const &txt,
                             arcade::Color txtColor) :
        _x(x),
        _y(y),
        _width(width),
        _height(height),
        _hasSprite(false),
        _spriteId(0),
        _color(bg),
        _text(txt),
        _textColor(txtColor),
        _clicked(false)
{
}

arcade::Component::Component(const arcade::Component &cmp)
{
    _x = cmp._x;
    _y = cmp._y;
    _width = cmp._width;
    _height = cmp._height;
    _hasSprite = cmp._hasSprite;
    _spriteId = cmp._spriteId;
    _color = cmp._color;
    _text = cmp._text;
    _textColor = cmp._textColor;
    _clicked = cmp._clicked;
}

void arcade::Component::setText(std::string text)
{
    _text = text;
}

void arcade::Component::setSprite(size_t id)
{
    _spriteId = id;
}
