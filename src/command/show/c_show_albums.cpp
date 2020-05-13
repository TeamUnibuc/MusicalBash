#include "c_show_albums.hpp"

CShowAlbums::CShowAlbums()
{}

void CShowAlbums::Execute()
{
    Knowledge::State::curr_state = Constants::State::W::Albums;
    
/// DEBUG
    auto album = Knowledge::Daddy_Player->getAlbums();
    Logger::Get() << "INFO: All albums count: " << album.size() << '\n';

} 