//
// Created by duhieu_b on 01/04/17.
//

#ifndef CPP_ARCADE_VECTOR2_HPP
#define CPP_ARCADE_VECTOR2_HPP

#include <form.h>

namespace arcade
{
    template <typename T>
    struct Vector2
    {
        T x;
        T y;
        Vector2();
        Vector2(Vector2 const& cpy);
        Vector2(T a, T b);
        Vector2 &operator=(Vector2 const& cpy);
        Vector2 &operator+(Vector2 const& a, Vector2 const& b);
        Vector2 &operator+=(Vector2 const& b);
        Vector2 &operator-=(Vector2 const& b);
        Vector2 &operator-(Vector2 const& a, Vector2 const& b);
        bool operator==(Vector2 const& comp);
        bool operator!=(Vector2 const& comp);
    };

    Vector2 &Vector2::operator=(const T &cpy)
    {
        x = cpy.x;
        y = cpy.y;
        return *this;
    }

    Vector2::Vector2() : x(0), y(0)
    {
    }

    Vector2::Vector2(Vector2 const &cpy) : x(cpy.x), y(cpy.y)
    {
    }

    Vector2::Vector2(T a, T b) : x(a), y(b)
    {
    }

    Vector2 &Vector2::operator+(Vector2 const& a,Vector2 const &b)
    {
        Vector2 res;
        res.x = a.x + b.x;
        res.y = a.y + b.y;
        return res;
    }

    Vector2 &Vector2::operator-(Vector2 const& a,Vector2 const &b)
    {
        Vector2 res;
        res.x = a.x + b.x;
        res.y = a.y + b.y;
        return res;
    }

    Vector2 &Vector2::operator+=(Vector2 const& b)
    {
        x += b.x;
        y += b.y;
        return (*this);
    }

    Vector2 &Vector2::operator-=(Vector2 const& b)
    {
        x -= b.x;
        y -= b.y;
        return (*this);
    }

    bool Vector2::operator==(Vector2 const &comp)
    {
        return (x == comp.x && y == comp.y);
    }

    bool Vector2::operator!=(Vector2 const &comp)
    {
        return (x != comp.x || y != comp.y);
    }

    typedef Vector2<int> Vector2i;
    typedef Vector2<float> Vector2f;
    typedef Vector2<double> Vector2d;
}

#endif //CPP_ARCADE_VECTOR2_HPP
