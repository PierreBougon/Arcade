//
// Created by duhieu_b on 09/04/17.
//

#ifndef CPP_ARCADE_NUMBER_HPP
#define CPP_ARCADE_NUMBER_HPP


#include <vector>
#include <cstddef>

namespace arcade
{
    class Score
    {
    private:
        std::vector<std::vector<size_t>> spritesID;
        std::vector<size_t> pos;
    public:
        Score();
        ~Score();

        void setScore(size_t pos);
        size_t getScore() const;
        std::vector<std::vector<size_t>> getSpiteId() const;
        const std::vector<size_t> &getPos() const;
    };
}


#endif //CPP_ARCADE_NUMBER_HPP
