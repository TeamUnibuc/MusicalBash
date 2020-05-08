#include "a_button_factory.hpp"

UniquePtr<UiElement> ButtonFactory::CreateButton(ButtonFactory::SideType type)
{
    switch (type) {
        case SideType::Home : {
            return std::make_unique<ColorButton>(200, 15, std::make_unique<CShowHome>(), 
                                                 sf::Color::Blue, sf::Color::Green);
        }
        case SideType::Albums : {
            return std::make_unique<ColorButton>(200, 22, std::make_unique<CShowAlbums>(), 
                                                 sf::Color::White, sf::Color::Yellow);
        }
    }
    return std::make_unique<ColorButton>(200, 30, std::make_unique<CShowAlbums>(), 
                                                 sf::Color::Black, sf::Color::Red);
}