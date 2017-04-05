//
// Created by Pierre Bougon on 03/04/17.
//

#ifndef CPP_ARCADE_AGAME_HPP_
#define CPP_ARCADE_AGAME_HPP_

#include "Tick.hpp"
#include "IGame.hpp"

namespace arcade
{
    class AGame: public IGame
    {
    protected:
        tick_t tickRate;

    public:
        tick_t getTick();
    };
}


#endif // !CPP_ARCADE_AGAME_HPP_
