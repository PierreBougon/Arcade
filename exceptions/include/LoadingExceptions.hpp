//
// Created by Pierre Bougon on 06/04/17.
//

#ifndef CPP_ARCADE_LOADINGEXCEPTIONS_HPP_
#define CPP_ARCADE_LOADINGEXCEPTIONS_HPP_

#include <stdexcept>

namespace arcade
{
    class LoadingExceptions : public std::runtime_error
    {
    public:
        LoadingExceptions(const std::string &error);

        virtual ~LoadingExceptions() throw();
    };

    class SoundLoadingError : public LoadingExceptions
    {
    public:
        SoundLoadingError(const std::string &error);

        virtual ~SoundLoadingError() throw();
    };

    class SpritesLoadingError : public LoadingExceptions
    {
    public:
        SpritesLoadingError(const std::string &error);

        virtual ~SpritesLoadingError() throw();
    };

    class DLLoadingError : LoadingExceptions
    {
    public:
        // Error enum to set a state if an error occurred in the DLL Loading
        enum class DLLError
        {
            NONE = -1,
            WINDOW_ERROR,
            UNDEFINED_ERROR,
            NO_LIB_LOADED_ERROR,
            NO_GAME_LOADED_ERROR,
            NB_ERRORS
        };

    public:
        DLLoadingError(const std::string &error_msg, DLLError _error);

        virtual ~DLLoadingError() throw();

        virtual DLLError getError() const;

    private:
        DLLError error;

    };
}


#endif // !CPP_ARCADE_LOADINGEXCEPTIONS_HPP_
