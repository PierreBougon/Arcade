//
// Created by Pierre Bougon on 02/04/17.
//

#include <iostream>
#include "Tick.hpp"

arcade::Tick::Tick() : baseTime(std::chrono::steady_clock::now()), tickrate(BASIC_TICK_RATE)
{}

bool arcade::Tick::isTick()
{
    std::chrono::duration<double> time_span =
            std::chrono::duration_cast<std::chrono::duration<double>>
                    (std::chrono::steady_clock::now() - baseTime);

    if (time_span.count() >= tickMs())
    {
        baseTime = std::chrono::steady_clock::now();
        return true;
    }
    return false;
}

void arcade::Tick::reset()
{
    baseTime = std::chrono::steady_clock::now();
}

void arcade::Tick::setTickrate(arcade::tick_t tickrate)
{
    this->tickrate = tickrate;
}

arcade::tick_t arcade::Tick::tickMs()
{
    return 1.0f / tickrate;
}
