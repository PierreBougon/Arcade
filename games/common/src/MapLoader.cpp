//
// Created by brout_m on 02/04/17.
//

#include <LifelessEntity.hpp>
#include <iostream>
#include "MapLoader.hpp"

arcade::MapLoader::MapLoader(const std::string &pathToMapCfg) :
        file(pathToMapCfg),
        Parsed(false),
        Height(0),
        Width(0)
{
    if (file.is_open())
        parse();
    else
        defaultMap(16, 16);
}

bool arcade::MapLoader::isFileParsed() const {
    return Parsed;
}

std::vector<arcade::Entity *> &arcade::MapLoader::getMap()
{
    return Map;
}

void arcade::MapLoader::parse()
{
    size_t y;
    size_t x;
    Vector2s vec;
    std::string line;

    y = 0;
    while (std::getline(file, line))
    {
        x = 0;
        Width = line.size();
        for (char tile : line)
        {
            vec.x = x;
            vec.y = y;
            if (tile == '#')
                Map.push_back(new LifelessEntity(vec,
                                                 arcade::TileType::BLOCK,
                                                 arcade::TileTypeEvolution::BLOCK,
                                                 Color::White,
                                                 true));
            else
                Map.push_back(new LifelessEntity (vec,
                                                  arcade::TileType::EMPTY,
                                                  arcade::TileTypeEvolution::EMPTY,
                                                  Color::Black,
                                                  false));
            ++x;
        }
        ++y;
    }
    Height = static_cast<size_t >(y);
}

size_t arcade::MapLoader::getWidth() const
{
    return Width;
}

size_t arcade::MapLoader::getHeight() const
{
    return Height;
}

arcade::MapLoader::~MapLoader()
{
    if (file.is_open())
        file.close();
    for (Entity *entity : Map)
        if (entity != nullptr)
            delete entity;
}

void arcade::MapLoader::defaultMap(size_t width, size_t height) {
    Vector2s vec;

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            vec.x = x;
            vec.y = y;
            Map.push_back(new LifelessEntity(vec,
                                             arcade::TileType::EMPTY,
                                             arcade::TileTypeEvolution::EMPTY,
                                             Color::Black,
                                             false));
        }
    }
    Height = height;
    Width = width;
}