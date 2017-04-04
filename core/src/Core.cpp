//
// Created by duhieu_b on 15/03/17.
//

#include <DLLoader.hpp>
#include <algorithm>
#include "../include/Core.hpp"

arcade::Core::Core()
{
}

arcade::Core::~Core()
{
}

void arcade::Core::init(std::string const &lib)
{
    pars.FeedVecLib("./lib");
    pars.FeedVecGame("./games");
    feedLib();
    feedGame();
    currentLib = findLib(lib);

    // Basic choice should be decided on a menu
    currentGame = findGame("./games/snake/snake.so");
}

void arcade::Core::run()
{
    while (isOpen())
    {
        //events
        if (currentGame && currentGame->getTick())
        {
            currentGame->process();
            playSound();
            // SOUNDMANAGER sound currentGame.
            switch (currentGame->getGameState())
            {
                case GameState::QUIT :
                    quitArcade();
                    break;
                case GameState::LOADING :
                    initGame();
                    break;
                case GameState::INGAME :
                    drawFrame();
                    break;
                case GameState::MENU :
//                    currentLib->updateGUI(currentGame->getGUI());
                    quitGame();
                    break;
                default:
                    break;
            }
        }
        else
        {
            // display arcade menu
        }
        currentLib->display();
    }
}

void arcade::Core::feedLib()
{
    for (std::vector<std::string>::const_iterator it = pars.getVecLib().begin(); it != pars.getVecLib().end(); it++)
    {
        DLLoader loader(*it);
        tabLib.push_back(loader.getInstance("getLib"));
    }
}

void arcade::Core::feedGame()
{
    for (std::vector<std::string>::const_iterator it = pars.getVecGame().begin(); it != pars.getVecGame().end(); it++)
    {
        DLLoader loader(*it);
        tabGame.push_back(loader.getInstance("getGame"));
    }
}

int arcade::Core::getIndexLib(std::string const &lib) const
{
    return (getIndexVec(lib, pars.getVecLib()));
}

int arcade::Core::getIndexGame(std::string const &game) const
{
    return (getIndexVec(game, pars.getVecGame()));
}

int arcade::Core::getIndexVec(std::string const &lib, std::vector<std::string> vec) const
{
    int i = 0;

    for (std::vector<std::string>::const_iterator it = pars.getVecLib().begin(); it != pars.getVecLib().end(); ++it)
    {
        if (*it == lib)
            return i;
        ++i;
    }
    return (-1);
}

arcade::AGame *arcade::Core::findGame(const std::string &game)
{
    std::vector<std::unique_ptr<arcade::AGame>>::iterator it =
            std::find_if(tabGame.begin(), tabGame.end(), [&game](std::string _game){
                return _game == game;
            });
    if (it == tabGame.end())
        return nullptr;
    return it->get();
}

arcade::IGfxLib *arcade::Core::findLib(const std::string &lib)
{
    std::vector<std::unique_ptr<arcade::IGfxLib>>::iterator it =
    std::find_if(tabLib.begin(), tabLib.end(), [&lib](std::string _lib){
        return _lib == lib;
    });
    if (it == tabLib.end())
        return nullptr;
    return it->get();
}

void arcade::Core::drawFrame()
{
    currentLib->updateMap(currentGame->getCurrentMap());
    currentLib->updateGUI(currentGame->getGUI());
}

void arcade::Core::initGame()
{
    currentLib->loadSounds(currentGame->getSoundsToLoad());
    currentLib->loadSprites(currentGame->getSpritesToLoad());
}

bool arcade::Core::isOpen() const
{
    return open;
}

void arcade::Core::quitGame()
{
    currentGame = nullptr;
}

void arcade::Core::quitArcade()
{
    // TODO check new implementation
    open = false;
}

void arcade::Core::playSound()
{
    currentLib->soundControl(currentGame->getSoundsToPlay());
}

void arcade::Core::sendNetwork()
{
    //currentGame->getNetworkToSend()
}
