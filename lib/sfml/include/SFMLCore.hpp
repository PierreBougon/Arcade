//
// Created by Pierre Bougon on 17/03/17.
//

#ifndef CPP_ARCADE_SFMLCORE_HPP_
#define CPP_ARCADE_SFMLCORE_HPP_


#include <IGfxLib.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
#include <map>
#include <SFML/Graphics/Sprite.hpp>

namespace arcade
{
    class SFMLCore : public IGfxLib
    {
    private:
        unsigned int                                                width;
        unsigned int                                                height;
        size_t                                                      x;
        size_t                                                      y;
        sf::RenderWindow                                            window;
        std::vector<std::unique_ptr<sf::Music>>                     sounds;
        std::vector<sf::Sprite>;

        // Static mapped attributes
        static std::map<sf::Event::EventType, arcade::EventType>    mappedEventType;
        static std::map<sf::Event::EventType, arcade::ActionType>   mappedEventAction;
        static std::map<sf::Keyboard::Key, arcade::KeyboardKey>     mappedKeyboard;

    public:
        SFMLCore();

        ~SFMLCore() override;


        bool pollEvent(Event &e) override;

        bool doesSupportSound() const override;

        void loadSounds(std::vector<std::pair<std::string, arcade::SoundType>> const &sounds) override;

        void soundControl(Sound const &sound) override;

        void updateMap(IMap const &map) override;

        void display() override;

        void clear() override;

        void loadSprites(std::vector<std::unique_ptr<ISprite>> &&sprites) override;

        void updateGUI(IGUI &gui) override;

    private:
        void updateEventType(Event &e, sf::Event &event);

        void updateMousePosition(MousePos &pos, sf::Vector2i sfPos);

        void drawMap();

        void drawGui();
    };
}


#endif // !CPP_ARCADE_SFMLCORE_HPP_
