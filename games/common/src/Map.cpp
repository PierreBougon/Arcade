//
// Created by brout_m on 02/04/17.
//

#include <cstddef>
#include "ITile.hpp"
#include "Map.hpp"

arcade::Map::Map(size_t width, size_t height, size_t nbLayers) :
    _map(nbLayers, t_layer (height, t_line (width, arcade::Tile())))
{
}

size_t arcade::Map::getLayerNb() const
{
    return _map.size();
}

size_t arcade::Map::getWidth() const
{
    return _map[0][0].size();
}

size_t arcade::Map::getHeight() const
{
    return _map[0].size();
}

const ITile &arcade::Map::at(size_t layer, size_t x, size_t y) const
{
    return static_cast<const ITile&>(_map[layer][y][x]);
}

void arcade::Map::addLayer()
{
    _map.push_back(t_layer(getHeight(), t_line(getWidth(), arcade::Tile())));
}

