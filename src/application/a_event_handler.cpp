#include "a_event_handler.hpp"

#include "a_knowledge.hpp"
#include "a_logger.hpp"
#include "a_constants.hpp"

namespace EventHandler
{

void Click(const sf::Event& ev)
{
    Logger::Get() << "Click at position: " << ev.mouseButton.x << ' ' << ev.mouseButton.y - Constants::kTopBarSize << '\n';

    Knowledge::SetEvent(ev);
}

void MouseWheelScrolled(const sf::Event& event)
{
    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
        Logger::Get() << "wheel type: vertical - ";
    else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
        Logger::Get() << "wheel type: horizontal - ";
    else
        Logger::Get() << "wheel type: unknown - " << std::endl;
    Logger::Get() << " wheel movement: " << event.mouseWheelScroll.delta;
    Logger::Get() << " mouse x: " << event.mouseWheelScroll.x;
    Logger::Get() << " mouse y: " << event.mouseWheelScroll.y << std::endl;
}

void DebugKeyDown()
{
    Logger::Get() << "Curr playing offset:  " << Knowledge::Daddy_Player->getActiveSongPlayingOffset() << '\n';
    Logger::Get() << "Curr song Length:  " << Knowledge::Daddy_Player->getActiveSongDuration() << '\n';
}

}