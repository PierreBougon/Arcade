//
// Created by Pierre Bougon on 17/03/17.
//

#ifndef CPP_ARCADE_SFMLCORE_HPP_
#define CPP_ARCADE_SFMLCORE_HPP_


#include <IGfxLib.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
#include <map>

namespace arcade
{
    class SFMLCore : public IGfxLib
    {
    private:
        unsigned int                                        width;
        unsigned int                                        height;
        size_t                                              x;
        size_t                                              y;
        std::map<sf::Event::EventType, arcade::EventType>   mappedEventType;
        std::map<sf::Event::EventType, arcade::ActionType>  mappedEventAction;
        std::map<sf::Keyboard::Key, arcade::KeyboardKey>    mappedKeyboard;
        std::unique_ptr<sf::RenderWindow>                   window;
        std::vector<std::unique_ptr<sf::Music>>             sounds;

    public:
        SFMLCore();

        ~SFMLCore() override;


        bool pollEvent(Event &e) override;

        bool doesSupportSound() const override;

        void loadSounds(std::vector<std::string> const &sounds) override;

        void playSound(int soundId) override;

        void setSize(size_t height, size_t width) override;

        void setPosition(size_t y, size_t x) override;

        void initializeWindow() override;

        void updateMap(IMap const &map) override;

        void updateGUI(IGUI const &gui) override;

        void display() override;

        void clear() override;


    private:
        void updateEventType(Event &e, sf::Event &event);

        void updateMousePosition(MousePos &pos, sf::Vector2i sfPos);
    };
}


#endif // !CPP_ARCADE_SFMLCORE_HPP_
