//
// Created by Pierre Bougon on 06/04/17.
//

#include <GameState.hpp>
#include "LoadingExceptions.hpp"

arcade::LoadingExceptions::LoadingExceptions(const std::string &error) : runtime_error(error)
{
}

arcade::LoadingExceptions::~LoadingExceptions() throw()
{
}

arcade::SoundLoadingError::SoundLoadingError(const std::string &error) : LoadingExceptions(error)
{}

arcade::SoundLoadingError::~SoundLoadingError() throw()
{

}

arcade::SpritesLoadingError::SpritesLoadingError(const std::string &error) : LoadingExceptions(error)
{}

arcade::SpritesLoadingError::~SpritesLoadingError() throw()
{

}

arcade::DLLoadingError::DLLoadingError(const std::string &error_msg, DLLError _error)
        : LoadingExceptions(error_msg), error(_error)
{}

arcade::DLLoadingError::~DLLoadingError() throw()
{

}

arcade::DLLoadingError::DLLError arcade::DLLoadingError::getError() const
{
    return error;
}
