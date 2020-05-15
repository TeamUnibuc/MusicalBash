#include "a_event_handler.hpp"

#include "a_knowledge.hpp"
#include "a_logger.hpp"
#include "a_constants.hpp"

namespace EventHandler
{

void Click()
{
    auto [x, y] = Knowledge::GetMousePoz();
    Logger::Get() << "Click at position: " << x << ' ' << y << '\n';
}

void MouseWheelScrolled(const sf::Event& event )
{
    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
        Logger::Get() << "wheel type: vertical - ";
    else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
        Logger::Get() << "wheel type: horizontal - ";
    else
        Logger::Get() << "wheel type: unknown - " << std::endl;
    Logger::Get() << " wheel movement: " << event.mouseWheelScroll.delta << '\n';
    // Logger::Get() << " mouse x: " << event.mouseWheelScroll.x;
    // Logger::Get() << " mouse y: " << event.mouseWheelScroll.y << std::endl;
}

void DebugKeyDown()
{
    // Logger::Get() << "Curr playing offset:  " << Knowledge::Daddy_Player->getActiveSongPlayingOffset() << '\n';
    // Logger::Get() << "Curr song Length:  " << Knowledge::Daddy_Player->getActiveSongDuration() << '\n';
    Logger::Get() << "Nr songs in Queue: " << Knowledge::Daddy_Player->GetPlayingQueue().size() << "\n";
    Logger::Get() << "Size of all music: " << Knowledge::Daddy_Player->getAllMusic().GetMusic().size() << '\n';

}

void Close(sf::RenderWindow& rw)
{
    Knowledge::Daddy_Player->Zip();
    rw.close();
    Logger::Get() << "The window was closed\n";
}

}