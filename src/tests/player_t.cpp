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

        auto album = player->CreateAlbum("data");

        std::vector <std::shared_ptr<PMusic>> content = album->GetMusic();
        cout << "Music in album:\n";
        for (auto i : content)
            cout << i->getName() << ": Duration -- " << i->getDuration() << '\n';

        player->addAlbumToQueue(album);

        player->PlayMusic();

        sf::sleep(sf::seconds(5));
        return 1;
    }
}