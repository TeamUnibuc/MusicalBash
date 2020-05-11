#ifndef INC_APPLICATION_KNOWLEDGE_HPP_
#define INC_APPLICATION_KNOWLEDGE_HPP_

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <utility>

#include "a_definitions.hpp"
#include "a_constants.hpp"
#include "player.hpp"

namespace Knowledge
{
    /// This enum tells the MainWindow what has to render
    namespace State
    {
        union Data
        {
            static SharedPtr<PPlaylist> curr_playlist;
            static SharedPtr<PAlbum> curr_album;
        };
    }

    extern Constants::State::W curr_state;

    extern UniquePtr<Player> Daddy_Player;

    void ResetEvent();

    void SetMousePoz(const std::pair<int, int>& where);

    std::pair<int,int> GetMousePoz();

    void SetEvent(sf::Event ev);

    sf::Event GetEvent();    
}

#endif