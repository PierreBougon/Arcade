//
// Created by Pierre Bougon on 04/04/17.
//

#include <chrono>
#include <cstdlib>
#include "Logger.hpp"
#include "Core.hpp"
#include "LoadingExceptions.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        Logger::log(Logger::Error, "Usage: ./arcade ./path/your_lib.so");
        return (EXIT_FAILURE);
    }
    std::srand(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
    arcade::Core arcadeCore;

    try
    {
        arcadeCore.init(av[1]);
    }
    catch (arcade::LoadingExceptions const &error)
    {
        error.what();
        return (EXIT_FAILURE);
    }
    // TODO: try catch for a game exception or something
    arcadeCore.run();

    return (EXIT_SUCCESS);
}
