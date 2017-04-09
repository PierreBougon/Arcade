//
// Created by duhieu_b on 09/04/17.
//

#include <memory>
#include <iostream>
#include "SpriteGenerator.hpp"
#include "Score.hpp"

arcade::Score::Score()
{
    spritesID = {
            {18, 19, 20, 21, 22, 23, 24, 25, 26, 27},
            {18, 19, 20, 21, 22, 23, 24, 25, 26, 27},
            {18, 19, 20, 21, 22, 23, 24, 25, 26, 27},
            {18, 19, 20, 21, 22, 23, 24, 25, 26, 27},
        };
    pos = {0, 0, 0, 4};
}

arcade::Score::~Score()
{

}

void arcade::Score::setScore(size_t Pos)
{
    size_t idx = pos.size() - 1;

    for (int i = 0; i < 4; ++i)
    {
        pos[idx - i] = Pos % 10;
        Pos /= 10;
    }
}

const std::vector<size_t> &arcade::Score::getPos() const
{
    return pos;
}

size_t arcade::Score::getScore() const
{
    size_t res(0);

    for (size_t i = 0; i < 4; ++i)
    {
        res *= 10;
        res += pos[i] % 10;
    }
    return (res);
}

std::vector<std::vector<size_t>> arcade::Score::getSpiteId() const
{
    return spritesID;
}

