#include "c_show_specific_playlist.hpp"

CShowSpecificPlaylist::CShowSpecificPlaylist(SharedPtr<PPlaylist> ptr) : playlist_(ptr)
{}

void CShowSpecificPlaylist::SetPlaylist(SharedPtr<PPlaylist> ptr)
{
    playlist_ = ptr;
}

void CShowSpecificPlaylist::Execute()
{
    if (not playlist_)
        throw null_pointer("Executing Show Specific Playlist with NullPointer");

    Knowledge::State::curr_state = Constants::State::W::ViewPlaylist;

    Knowledge::State::data.curr_playlist = playlist_;
}