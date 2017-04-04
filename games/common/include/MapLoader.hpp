//
// Created by brout_m on 02/04/17.
//

#ifndef CPP_ARCADE_MAPLOADER_HPP
# define CPP_ARCADE_MAPLOADER_HPP

# include <fstream>
# include <string>
# include <vector>
# include "Entity.hpp"

namespace arcade
{
    class MapLoader
    {
    public:
        ~MapLoader();
        MapLoader(std::string const& pathToMapCfg);
        bool isFileParsed() const;
        std::vector<arcade::Entity> &getMap();
        size_t getWidth() const;
        size_t getHeight() const;

    private:
        std::ifstream file;
        bool Parsed;
        size_t Height;
        size_t Width;
        std::vector<arcade::Entity> Map;

        void parse();
    };
}

#endif //CPP_ARCADE_MAPLOADER_HPP