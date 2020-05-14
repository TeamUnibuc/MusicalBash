#include "a_knowledge.hpp"

namespace Knowledge
{
UniquePtr<Player> Daddy_Player;

/// State holding information
Constants::State::W   State::curr_state = Constants::State::W::Home;
State::Data           State::data;

/// Global variables but available only 
/// in this translation unit so we are safe

static sf::Event event_;
static std::pair<int, int> mouse_poz_;


/// Functions so we can use those global variables!
void ResetEvent()
{
    // mouse_poz_ = {-1, -1};
    event_ = Constants::kMockEvent;
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

}