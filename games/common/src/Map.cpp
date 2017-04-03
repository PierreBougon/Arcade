//
// Created by brout_m on 02/04/17.
//

#include <cstddef>
#include "ITile.hpp"
#include "Map.hpp"

arcade::Map::Map(std::string const& path,  size_t nbLayers) :
        _mapLoader(path),
        _map(nbLayers, t_layer (_mapLoader.getHeight(), t_line (_mapLoader.getWidth(), arcade::Tile())))
{
    updateLayer(_mapLoader.getMap(), 0);
}

size_t arcade::Map::getLayerNb() const
{
    return _map.size();
}

size_t arcade::Map::getWidth() const
{
    return _mapLoader.getWidth();
}

size_t arcade::Map::getHeight() const
{
    return _mapLoader.getHeight();
}

const ITile &arcade::Map::at(size_t layer, size_t x, size_t y) const
{
    return static_cast<const ITile&>(_map[layer][y][x]);
}

void arcade::Map::updateLayer(std::vector<arcade::Entity> &entities, size_t layer)
{
    for (Entity &entity : entities) {
        const Vector2i &abs = entity.getAbs();
        _map[layer][abs.y][abs.x] = entity;
    }
}