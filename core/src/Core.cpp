//
// Created by duhieu_b on 15/03/17.
//

#include <algorithm>
#include "DLLoader.hpp"
#include "Logger.hpp"
#include "Core.hpp"

arcade::Core::Core() :
{
    loadDependencies();

    currentLib = findLib("./lib/sfml/lib_arcade_sfml.so");

    //TODO: Basic choice should be decided on a menu
    currentGame = findGame("./games/snake/snake.so");
}

arcade::Core::Core(std::string const &lib)
{
    loadDependencies();

    currentLib = findLib(lib);
    //TODO: Basic choice should be decided on a menu
    currentGame = findGame("./games/snake/snake.so");
}

arcade::Core::~Core()
{
}

void arcade::Core::init(std::string const &lib)
{
    loadDependencies();

    currentLib = findLib(lib);
    //TODO: Basic choice should be decided on a menu
    currentGame = findGame("./games/snake/snake.so");
}

void arcade::Core::run()
{
    while (isOpen())
    {
        manageEvents();
        if (!isOpen())
            return;
        if (currentGame && currentGame->getTick())
        {
            currentGame->process();
            playSound();
            switch (currentGame->getGameState())
            {
                case GameState::QUIT :
                    quitArcade();
                    return;
                case GameState::LOADING :
                    initGame();
                    break;
                case GameState::INGAME :
                    drawFrame();
                    break;
                case GameState::MENU :
                    quitGame();
                    break;
                default:
                    break;
            }
        }
        else
        {
            //TODO: display arcade menu
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
    {
        Logger::log(Logger::Error,
                   game + " : This game cannot be loaded, check out your games/ directory to see your games");
        return nullptr;
    }
    return it->get();
}

arcade::IGfxLib *arcade::Core::findLib(const std::string &lib)
{
    std::vector<std::unique_ptr<arcade::IGfxLib>>::iterator it =
    std::find_if(tabLib.begin(), tabLib.end(), [&lib](std::string _lib){
        return _lib == lib;
    });
    if (it == tabLib.end())
    {
        Logger::log(Logger::Error,
                    lib + " : This lib cannot be loaded, check out your lib/ directory to see your library");
        return nullptr;
    }
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

void arcade::Core::manageEvents()
{
    Event               event;
    std::vector<Event>  _events;

    while (currentLib->pollEvent(event))
    {
        switch (event.type)
        {
            case EventType::ET_QUIT :
                open = false;
                break;
            default:
                _events.push_back(event);
                break;
        }
    }
    if (currentGame)
        currentGame->notifyEvent(std::move(_events));
    else
        events = &(std::move(_events));
}

void arcade::Core::loadDependencies()
{
    pars.FeedVecLib("./lib");
    pars.FeedVecGame("./games");
    feedLib();
    feedGame();
}
