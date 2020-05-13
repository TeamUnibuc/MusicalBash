#include "c_show_albums.hpp"

CShowAlbums::CShowAlbums()
{}

/// TO DO
void CShowAlbums::Execute()
{
    auto album = Knowledge::Daddy_Player->getAlbums();
    Logger::Get() << "All albums:\n";
    for (auto i : album) {
        Logger::Get() << "Album at " << i->GetName() << " contains:\n";
        for (auto j : i->GetMusic())
            Logger::Get() << j->getName() << '\n';
    }
    Logger::Get() << "Command ShowAlbums Not implemented !!! \n";
} 