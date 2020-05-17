#include "c_delete_song_from_playlist.hpp"

CDeleteSongFromPlaylist::CDeleteSongFromPlaylist(SharedPtr<PMusic> music, SharedPtr<PPlaylist> playlist) :
    music_(music), playlist_(playlist)
{}

void CDeleteSongFromPlaylist::SetPlaylist(SharedPtr<PPlaylist> ptr)
{
    playlist_ = ptr;
}

void CDeleteSongFromPlaylist::SetMusic(SharedPtr<PMusic> ptr)
{
    music_ = ptr;
}

void CDeleteSongFromPlaylist::Execute()
{
    if (not music_)
        throw null_pointer("Executing command DeleteSongFromPlaylist with NullPointer for Music");
    if (not playlist_)
        throw null_pointer("Executing command DeleteSongFromPlaylist with NullPointer for Playlist");
    
    playlist_->DeleteSong(music_);
    Logger::Get() << "INFO:  Command Delete Song From Playlist Called!!!";
}