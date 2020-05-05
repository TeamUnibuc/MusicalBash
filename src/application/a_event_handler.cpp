#include "a_event_handler.hpp"

#include "a_knowledge.hpp"
#include "a_logger.hpp"

namespace EventHandler
{

void Click(const sf::Event& ev)
{
    Logger::Get() << "Click at position: " << ev.mouseButton.x << ' ' << ev.mouseButton.y << '\n';

    Knowledge::SetEvent(ev);
}

void MouseWheelScrolled(const sf::Event& event)
{
    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
        Logger::Get() << "wheel type: vertical" << std::endl;
    else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
        Logger::Get() << "wheel type: horizontal" << std::endl;
    else
        Logger::Get() << "wheel type: unknown" << std::endl;
    Logger::Get() << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
    Logger::Get() << "mouse x: " << event.mouseWheelScroll.x << std::endl;
    Logger::Get() << "mouse y: " << event.mouseWheelScroll.y << std::endl;
}

}