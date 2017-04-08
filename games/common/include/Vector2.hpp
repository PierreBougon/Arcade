//
// Created by duhieu_b on 01/04/17.
//

#ifndef CPP_ARCADE_VECTOR2_HPP
#define CPP_ARCADE_VECTOR2_HPP

#include <ostream>

namespace arcade
{
    template <typename T>
    struct Vector2
    {
        //////////////////////
        /// Member data
        //////////////////////
        T x;
        T y;

        //////////////////////
        /// Constructors
        //////////////////////
        Vector2() : x(0), y(0)
        {}

        Vector2(T a, T b) : x(a), y(b)
        {}

        Vector2(Vector2<T> const& cpy) : x(cpy.x), y(cpy.y)
        {}


        //////////////////////
        /// Operators
        //////////////////////
        Vector2<T> &operator=(Vector2<T> const& cpy)
        {
            x = cpy.x;
            y = cpy.y;
            return *this;
        }

        Vector2<T> &operator+(Vector2 const& b)
        {
            Vector2 res;
            res.x = x + b.x;
            res.y = y + b.y;
            return res;
        }

        Vector2<T> &operator+=(Vector2<T> const& b)
        {
            x += b.x;
            y += b.y;
            return (*this);
        }

        Vector2<T> &operator-=(Vector2<T> const& b)
        {
            x -= b.x;
            y -= b.y;
            return (*this);
        }

        Vector2<T> &operator-(Vector2 const& b)
        {
            Vector2 res;
            res.x = x + b.x;
            res.y = y + b.y;
            return res;
        }

        bool operator==(Vector2<T> const& comp) const
        {
            return (x == comp.x && y == comp.y);
        }

        bool operator!=(Vector2<T> const& comp) const
        {
            return (x != comp.x || y != comp.y);
        }
    };

    /// Overload left stream operator for Vector2 to be able to easily print it
    template <typename T>
    std::ostream &operator<<(std::ostream &os, const Vector2<T> &vector2)
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
