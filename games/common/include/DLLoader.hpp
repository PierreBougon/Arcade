//
// Created by brout_m on 07/03/17.
//

#ifndef DLLOADER_H_
# define DLLOADER_H_

# include <dlfcn.h>
# include <string>

template <typename T>
class DLLoader
{
public:
    ~DLLoader<T>();
    DLLoader<T>(std::string const& _library);
    T *getInstance(std::string const& entrypoint);

private:
    std::string library;
    void *handle;
    T *(*func)();
};

template <typename T>
DLLoader<T>::~DLLoader() {
    if (handle)
        dlclose(handle);
}

template <typename T>
DLLoader<T>::DLLoader(std::string const &_library) :
        library(_library),
        handle(dlopen(library.c_str(), RTLD_NOW)),
        func(nullptr)
{
}

template <typename T>
T *DLLoader<T>::getInstance(std::string const &entrypoint) {
    if (!handle)
        return (nullptr);
    if (func == nullptr) {
        dlerror();
        *(void **)(&func) = dlsym(handle, entrypoint.c_str());
        if (dlerror()) {
            func = nullptr;
            return nullptr;
        }
    }
    return func();
}

#endif //DLLOADER_H_