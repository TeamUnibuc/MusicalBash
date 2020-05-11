#include "a_knowledge.hpp"

namespace Knowledge
{
UniquePtr<Player> Daddy_Player;

Constants::State::W curr_state = Constants::State::W::Home;

/// Global variables but available only 
/// in this translation unit so we are safe

/// Private data
static const sf::Event kMockEvent = {sf::Event::JoystickConnected, {}};

static sf::Event event_;
static std::pair<int, int> mouse_poz_;


/// Functions so we can use those global variables!
void Reset()
{
    mouse_poz_ = {-1, -1};
    event_ = kMockEvent;
}

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

void SetEvent(sf::Event ev)
{
    event_ = ev;
}

std::string GetActiveSongNameOrEmpty()
{
    if (-1 == Daddy_Player->getPlayingStatus())
        return "- - - - -";
    return Daddy_Player->getActiveSong()->getName();
}

}