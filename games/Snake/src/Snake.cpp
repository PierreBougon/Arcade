//
// Created by duhieu_b on 03/04/17.
//

#include <PlayerControlSnake.hpp>
#include "../include/Snake.hpp"

arcade::GameState arcade::Snake::getGameState() const
{
    return state;
}

void arcade::Snake::notifyEvent(std::vector<arcade::Event> &&events)
{

}

void arcade::Snake::notifyNetwork(std::vector<arcade::NetworkPacket> &&events)
{

}

std::vector<arcade::NetworkPacket> &&arcade::Snake::getNetworkToSend()
{
    return <#initializer#>;
}

void arcade::Snake::process()
{

}

std::vector<std::unique_ptr<arcade::ISprite>> &&arcade::Snake::getSpritesToLoad() const
{
    return <#initializer#>;
}

std::vector<std::string> arcade::Snake::getSoundsToLoad() const
{
    return nullptr;
}

std::vector<int> &&arcade::Snake::getSoundsToPlay()
{
    return <#initializer#>;
}

const arcade::IMap &arcade::Snake::getCurrentMap() const
{
    return <#initializer#>;
}

const arcade::IGUI &arcade::Snake::getGUI() const
{
    return <#initializer#>;
}

arcade::Snake::Snake() : gameMap("./assets/map.txt", 2)
{
    move = MOVE_LEFT;
    //action = MOVE;
    state = LOADING;
    createPlayer();
    putFoodInMap();
}

arcade::PlayerInputs arcade::Snake::getMove() const
{
    return move;
}

/*arcade::actionPlayer arcade::Snake::getAction() const
{
    return action;
}*/

void arcade::Snake::createPlayer()
{
    Vector2i pos;
    size_t y = gameMap.getHeight() / 2;
    size_t x = gameMap.getWidth() / 2 - 2;

    pos.x = static_cast<int>(x);
    pos.y = static_cast<int>(y);
    entities.push_back(PlayerControlSnake(pos, TileType::EVIL_DUDE, TileTypeEvolution::PLAYER, Color::Cyan));
    for (int i = 0; i < 3; ++i)
    {

    }


}

void arcade::Snake::putFoodInMap()
{
    Vector2i pos;

    pos.x = static_cast<int>(rand() % gameMap.getWidth());
    pos.y = static_cast<int>(rand() % gameMap.getHeight());

}
