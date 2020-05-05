#ifndef INC_APPLICATION_EVENT_HANDLER_
#define INC_APPLICATION_EVENT_HANDLER_

#include <SFML/Window.hpp>
#include <iostream>

/// Should contain a function for each event to handle from the main loop
namespace EventHandler
{
    extern sf::Event event_;
    extern std::pair<int, int> mouse_poz_;

    void ResetKnowledge();

    sf::Event GetEvent();

    void SetMousePoz(const std::pair<int, int>& where);

    std::pair<int, int> GetMousePoz();

    void ClickAtPosition(int clickX, int clickY);

    void MouseWheelScrolled(sf::Event event);
};

#endif // INC_APPLICATION_EVENT_HANDLER_