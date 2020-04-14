#include "p_playlist.hpp"

#include <sstream>

PPlaylist::PPlaylist() { }

PPlaylist::PPlaylist(std::string name)
{
    name_ = name;
}

void PPlaylist::AddMusic(std::shared_ptr<PMusic> music)
{
    content_.push_back(music);
}
