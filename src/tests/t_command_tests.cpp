#include "t_command_tests.hpp"

namespace unit_tests
{
    bool TestDirSelectCommand()
    {
        CImportAlbum importAlbum;
        importAlbum.Execute();


        auto album = Knowledge::Daddy_Player->getAlbums();
        Logger::Get() << "All albums after the current addition:\n";
        for (auto i : album) {
            Logger::Get() << "Album at " << i->GetName() << " contains:\n";
            for (auto j : i->GetMusic())
                Logger::Get() << j->getName() << '\n';
        }
        return 1;
    }

    bool TestCreatePlaylist()
    {
        CCreatePlaylists createPlaylist;
        createPlaylist.Execute();

        
        auto playlists = Knowledge::Daddy_Player->getPlaylists();
        Logger::Get() << "All playlists after the current addition:\n";
        for (auto i : playlists) {
            Logger::Get() << "Playlist at " << i->GetName() << " contains:\n";
            for (auto j : i->GetMusic())
                Logger::Get() << j->getName() << '\n';
        }

        return 1;
    }
}