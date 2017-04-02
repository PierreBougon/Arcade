//
// Created by Pierre Bougon on 02/04/17.
//

#ifndef CPP_ARCADE_TICK_HPP_
#define CPP_ARCADE_TICK_HPP_

#include <chrono>

namespace arcade
{
    class Tick
    {
        /// Static const attributes
    public:
        /// Tick rate is the number of the tick per second your game will process
        constexpr static float TICK_RATE    = 128.0f;
        constexpr static float TICK_MS      = 1.0f / TICK_RATE;


    private:
        std::chrono::steady_clock::time_point     baseTime;

    public:
        Tick();

        bool isTick();

        void reset();
    };
}


#endif // !CPP_ARCADE_TICK_HPP_
