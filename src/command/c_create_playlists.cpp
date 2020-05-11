#include "c_create_playlists.hpp"

CCreatePlaylists::CCreatePlaylists()
{}

/// TO DO
void CCreatePlaylists::Execute()
{
    CGetUserInput get_user_input("Please enter the playlist name:");
    get_user_input.Execute();
    Knowledge::Daddy_Player->CreatePlaylist(get_user_input.GetResult());
    
    Logger::Get() << "Playlist " << get_user_input.GetResult() << " has been created" << '\n';
}