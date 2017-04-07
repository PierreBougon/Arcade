//
// Created by brout_m on 07/03/17.
//

#ifndef DLLOADER_H_
# define DLLOADER_H_

# include <dlfcn.h>
# include <string>
# include "LoadingExceptions.hpp"

namespace arcade
{
    template <typename T>
    class DLLoader
    {


    public:

        ~DLLoader()
        {
            if (handle)
                dlclose(handle);
        }

        DLLoader(std::string const &_library) :
                library(_library),
                handle(dlopen(library.c_str(), RTLD_NOW)),
                func(nullptr),
                error(DLLoadingError::DLLError::NONE)
        {}

        T *getInstance(std::string const &entrypoint)
        {
            if (!handle)
                return (nullptr);
            if (func == nullptr)
            {
                dlerror();

                try
                {
                    *(void **)(&func) = dlsym(handle, entrypoint.c_str());
                    if (dlerror())
                    {
                        func = nullptr;
                        return nullptr;
                    }
                }
                catch (DLLoadingError _error)
                {
                    error = _error.getError();
                }
            }
            return func();
        }

        DLLoadingError::DLLError getError() const
        {
            return error;
        }

    private:
        std::string                 library;
        void                        *handle;
        T                           *(*func)();
        DLLoadingError::DLLError    error;
    };
}




#endif // !DLLOADER_H_
