//
// Created by brout_m on 02/04/17.
//

#include <LifelessEntity.hpp>
#include "MapLoader.hpp"

arcade::MapLoader::MapLoader(const std::string &pathToMapCfg) :
        file(pathToMapCfg),
        Parsed(false),
        Height(0),
        Width(0)
{
    parse();
}

bool arcade::MapLoader::isFileParsed() const {
    return Parsed;
}

std::vector<arcade::Entity> &arcade::MapLoader::getMap() const
{
    return Map;
}

void arcade::MapLoader::parse()
{
    int y;
    int x;
    std::string line;

    y = 0;
    while (std::getline(file, line))
    {
        x = 0;
        Width = line.size();
        for (char tile : line)
        {
            if (tile == '#')
                Map.emplace_back(LifelessEntity({x, y},
                                                arcade::TileType::BLOCK,
                                                arcade::TileTypeEvolution::BLOCK,
                                                Color::White,
                                                true));
            else
                Map.emplace_back(LifelessEntity({x, y},
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
    file.close();
}