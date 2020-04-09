#include "tests/player_t.hpp"

#include <memory>
#include <stdexcept>

namespace unit_tests
{
    bool TestBasicFunctionalityPlayer()
    {
        using std::cout;
    
        cout << ".";

        std::shared_ptr<Player> player(new Player);

        player->CreateAlbum("data");

        player->addAlbumToQueue("data");

        player->PlayMusic();

        sf::sleep(sf::seconds(5));
        return 1;
    }
}