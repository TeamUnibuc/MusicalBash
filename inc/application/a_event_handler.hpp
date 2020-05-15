#ifndef INC_APPLICATION_EVENT_HANDLER_
#define INC_APPLICATION_EVENT_HANDLER_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

/// Should contain a function for each event to handle from the main loop
namespace EventHandler
{
    void Click();

    void MouseWheelScrolled(const sf::Event& event);

    void DebugKeyDown();

    void Close(sf::RenderWindow& rw);
};

#endif // INC_APPLICATION_EVENT_HANDLER_