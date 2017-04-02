//
// Created by Pierre Bougon on 02/04/17.
//

#include <iostream>
#include "Tick.hpp"

arcade::Tick::Tick() : baseTime(std::chrono::steady_clock::now())
{}

bool arcade::Tick::isTick()
{
    std::chrono::duration<double> time_span =
            std::chrono::duration_cast<std::chrono::duration<double>>
                    (std::chrono::steady_clock::now() - baseTime);

    if (time_span.count() >= TICK_MS)
    {
        std::cout << time_span.count() << std::endl;
        baseTime = std::chrono::steady_clock::now();
        return true;
    }
    return false;
}

void arcade::Tick::reset()
{
    baseTime = std::chrono::steady_clock::now();
}
