//
// Created by brout_m on 02/04/17.
//

#ifndef CPP_ARCADE_MAP_HPP
# define CPP_ARCADE_MAP_HPP

# include <vector>
# include "IMap.hpp"
# include "Tile.hpp"

namespace arcade
{
    class Map : public IMap
    {
    public:
        // Constructors
        virtual ~Map() {};
        Map(size_t width, size_t height, size_t nbLayers = 1);

        size_t getLayerNb() const;
        size_t getWidth() const;
        size_t getHeight() const;
        const ITile &at(size_t layer, size_t x, size_t y) const;
        void addLayer();
        void consolidate()

    private:
        typedef std::vector<Tile>       t_line;
        typedef std::vector<t_line>     t_layer;
        typedef std::vector<t_layer>    t_map;

        // deleted canonical form
        Map(Map const &map) = delete;
        Map &operator=(Map const &map) = delete;

        // members
        t_map   _map;
    };
}

#endif //CPP_ARCADE_MAP_HPP
