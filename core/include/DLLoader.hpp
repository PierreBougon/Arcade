//
// Created by brout_m on 07/03/17.
//

#ifndef DLLOADER_H_
# define DLLOADER_H_

# include <dlfcn.h>
# include <string>

namespace arcade
{
    // Error enum to set a state if an error occurred in the DLL Loading
    enum class DLLError
    {
        NONE = -1,
        WINDOW_ERROR,
        UNDEFINED_ERROR,
        NB_ERRORS
    };

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
                error(DLLError::NONE)
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
                catch (std::bad_alloc)
                {
                    error = DLLError::UNDEFINED_ERROR;
                }
            }
            return func();
        }

        DLLError getError() const
        {
            return error;
        }

    private:
        std::string library;
        void *handle;
        T *(*func)();
        DLLError error;
    };
}




#endif // !DLLOADER_H_