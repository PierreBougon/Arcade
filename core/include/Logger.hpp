//
// Created by Pierre Bougon on 03/02/17.
//

#ifndef NANOTEKSPICE_LOGGER_H_
#define NANOTEKSPICE_LOGGER_H_


#include <string>

namespace Debug
{
    extern bool DEBUG_MODE;
}

class Logger
{
public:

    enum Level
    {
        DEBUG = 0,
        Info,
        Warning,
        Error,
    };

    static void log(Level lvl, std::string msg, bool abort = false);
};


#endif // !NANOTEKSPICE_LOGGER_H_
