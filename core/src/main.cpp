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

    try
    {
        arcade::Core arcadeCore(av[1]);
        arcadeCore.run();
    }
    catch (arcade::DLLoadingError const &error)
    {
        //Logger::log(Logger::Error, error.what());
        return (EXIT_FAILURE);
    }
    // TODO: try catch for a game exception or something

    return (EXIT_SUCCESS);
}
