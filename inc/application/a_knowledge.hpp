#ifndef INC_APPLICATION_KNOWLEDGE_HPP_
#define INC_APPLICATION_KNOWLEDGE_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <utility>

#include "a_constants.hpp"
#include "player.hpp"

namespace Knowledge
{
    extern UniquePtr<Player> Daddy_Player;

    void Reset();

    void SetMousePoz(const std::pair<int, int>& where);

    std::pair<int,int> GetMousePoz();

    void SetEvent(sf::Event ev);

    sf::Event GetEvent();    
}

#endif