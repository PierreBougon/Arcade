//
// Created by Pierre Bougon on 15/03/17.
//

#include <algorithm>
#include "DLLoader.hpp"
#include "Logger.hpp"
#include "Core.hpp"

arcade::Core::Core() : tabLib(), tabGame(), pars(),
                       open(false), events(),
                       currentLib(nullptr), currentGame(nullptr)
{
    loadDependencies();

    currentLib = findLib("./lib/sfml/lib_arcade_sfml.so");

    //TODO: Basic choice should be decided on a menu
    currentGame = findGame("./games/snake/snake.so");
}

arcade::Core::Core(std::string const &lib) : tabLib(), tabGame(), pars(),
                                             open(false), events(),
                                             currentLib(nullptr), currentGame(nullptr)
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
        DLLoader<IGfxLib> loader(*it);
        if (loader.getError() == DLLError::NONE)
        {
            IGfxLib *lib_ptr = loader.getInstance("getLib");
            std::unique_ptr<IGfxLib> lib(lib_ptr);
            tabLib.push_back(std::move(lib));
        }
        else
        {
            //TODO: manage error
        }
    }
}

void arcade::Core::feedGame()
{
    for (std::vector<std::string>::const_iterator it = pars.getVecGame().begin(); it != pars.getVecGame().end(); it++)
    {
        DLLoader<IGame> loader(*it);
        if (loader.getError() == DLLError::NONE)
        {
            IGame *game_ptr = loader.getInstance("getGame");
            std::unique_ptr<IGame> game(game_ptr);
            //tabGame.push_back(game);
        }
        else
        {
            //TODO: manage error
        }
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

    for (std::vector<std::string>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (*it == lib)
            return i;
        ++i;
    }
    return (-1);
}


arcade::IGame *arcade::Core::findGame(const std::string &game)
{
    std::vector<std::string>::const_iterator it =
            std::find_if(pars.getVecGame().begin(), pars.getVecGame().end(), [game](std::string const &_game){
                return _game == game;
            });
    if (it == pars.getVecGame().end())
    {
        Logger::log(Logger::Error,
                   game + " : This game cannot be loaded, check out your games/ directory to see your games");
        return nullptr;
    }
    return tabGame[std::distance(it, pars.getVecGame().begin())].get();
}

arcade::IGfxLib *arcade::Core::findLib(const std::string &lib)
{
    std::vector<std::string>::const_iterator it =
    std::find_if(pars.getVecLib().begin(), pars.getVecLib().end(), [lib](std::string const &_lib){
        return _lib == lib;
    });
    if (it == pars.getVecLib().end())
    {
        Logger::log(Logger::Error,
                    lib + " : This lib cannot be loaded, check out your lib/ directory to see your library");
        return nullptr;
    }
    return tabLib[std::distance(it, pars.getVecLib().begin())].get();
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
        events = _events;
}

void arcade::Core::loadDependencies()
{
    pars.FeedVecLib("./lib");
    pars.FeedVecGame("./games");
    feedLib();
    feedGame();
}
