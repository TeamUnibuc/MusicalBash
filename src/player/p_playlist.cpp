#include "p_playlist.hpp"

PPlaylist::PPlaylist() { }

PPlaylist::PPlaylist(std::string name)
{
    name_ = name;
}

void PPlaylist::addMusic(std::shared_ptr<PMusic> music)
{
    content_.push_back(music);
}