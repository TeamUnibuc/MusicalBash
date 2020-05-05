#ifndef INC_APPLICATION_KNOWLEDGE_HPP_
#define INC_APPLICATION_KNOWLEDGE_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <utility>

namespace Knowledge
{
    void Reset();

    void SetMousePoz(const std::pair<int, int>& where);

    std::pair<int,int> GetMousePoz();

    void SetEvent(sf::Event ev);

    sf::Event GetEvent();    
}

#endif