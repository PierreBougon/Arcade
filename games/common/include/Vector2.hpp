//
// Created by duhieu_b on 01/04/17.
//

#ifndef CPP_ARCADE_VECTOR2_HPP
#define CPP_ARCADE_VECTOR2_HPP

#include <form.h>
#include <ostream>

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

    /// Overload left stream operator for Vector2 to be able to easily print it
    std::ostream &operator<<(std::ostream &os, const Vector2 &vector2);

    Vector2 &Vector2::operator=(const Vector2 &cpy)
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

    template <typename T>
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

    std::ostream &arcade::operator<<(std::ostream &os, const Vector2 &vector2)
    {
        os << "x: " << vector2.x << " y: " << vector2.y;
        return os;
    }

    typedef Vector2<int>            Vector2i;
    typedef Vector2<float>          Vector2f;
    typedef Vector2<double>         Vector2d;
    typedef Vector2<size_t>         Vector2s;
    typedef Vector2<unsigned int>   Vector2u;
}

#endif //CPP_ARCADE_VECTOR2_HPP
