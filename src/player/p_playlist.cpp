#include "p_playlist.hpp"

#include <sstream>

PPlaylist::PPlaylist() { }

PPlaylist::PPlaylist(std::string name)
{
    name_ = name;
}

void PPlaylist::DeleteSong(const std::shared_ptr<PMusic> music)
{
    if (find(content_.begin(), content_.end(), music) == content_.end())
        throw bad_behaviour("Attempted to delete from a playlist a song thats not in the playlist");
    
    content_.erase(find(content_.begin(), content_.end(), music));
}