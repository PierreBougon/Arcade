//
// Created by Pierre Bougon on 04/04/17.
//

#include <cstdlib>
#include "Logger.hpp"
#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        Logger::log(Logger::Error, "Usage: ./arcade ./path/your_lib.so");
        return (EXIT_FAILURE);
    }

    arcade::Core arcadeCore;

    arcadeCore.init(av[1]);
    arcadeCore.run();

    return (EXIT_SUCCESS);
}