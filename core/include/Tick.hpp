//
// Created by Pierre Bougon on 02/04/17.
//

#ifndef CPP_ARCADE_TICK_HPP_
#define CPP_ARCADE_TICK_HPP_

#include <chrono>
#include "IGame.hpp"

namespace arcade
{

    class Tick
    {
        ////////////////////////////////////
        /// Static const attributes
        ////////////////////////////////////
    public:
        constexpr static tick_t BASIC_TICK_RATE    = 128.0f;


    private:
        std::chrono::steady_clock::time_point       baseTime;
        /// Tick rate is the number of the tick per second your game will process
        tick_t                                      tickrate;

    public:
        Tick();

        bool isTick();

        void setTickrate(tick_t tickrate);

        void reset();

        tick_t tickMs();
    };
}


#endif // !CPP_ARCADE_TICK_HPP_
