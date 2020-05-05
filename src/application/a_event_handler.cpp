#include "a_event_handler.hpp"

namespace EventHandler
{
/// Global but in a namespace variables
sf::Event           event_;
std::pair<int, int> mouse_poz_;

void ResetKnowledge()
{
    sf::Event mockEvent;
    mockEvent.type = sf::Event::JoystickConnected;
    event_ = mockEvent;
}

/// Functions so we can use those global variables!
void SetMousePoz(const std::pair<int, int>& where)
{
    mouse_poz_ = where;
}

std::pair<int,int> GetMousePoz()
{
    return mouse_poz_;
}

sf::Event GetEvent()
{
    return event_;
}

/// TO DO
void ClickAtPosition(int clickX, int clickY)
{
    std::cerr << "Click at position: " << clickX << ' ' << clickY << '\n';
    /// Something with knowledge
}

void MouseWheelScrolled(sf::Event event)
{
    event_ = event;

    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
        std::cout << "wheel type: vertical" << std::endl;
    else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
        std::cout << "wheel type: horizontal" << std::endl;
    else
        std::cout << "wheel type: unknown" << std::endl;
    std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
    std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
    std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
}

}