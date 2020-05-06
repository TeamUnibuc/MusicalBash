#ifndef INC_APPLICATION_EVENT_HANDLER_
#define INC_APPLICATION_EVENT_HANDLER_

#include <SFML/Window.hpp>
#include <iostream>

/// Should contain a function for each event to handle from the main loop
namespace EventHandler
{
    void Click(const sf::Event& event);

    void MouseWheelScrolled(const sf::Event& event);
};

#endif // INC_APPLICATION_EVENT_HANDLER_