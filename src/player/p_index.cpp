#include "p_index.hpp"

#include <stdexcept>
#include <sstream>

PIndex::PIndex() { }

std::string PIndex::Zip() const
{
    /* first line contains the number of albums
    next each line starts with size of zip of album
    followed by the album zip. Then the same for the playlists*/
    /// TODO:
}

void PIndex::Restore(std::string zipped)
{
    /// TODO:

}

void PIndex::addAlbumToIndex(std::string path)
{
    if (palbum_.find(path) != palbum_.end())
        throw std::runtime_error("Existing album is added again!");
    palbum_[path] = std::shared_ptr<PAlbum> (new PAlbum);

    palbum_[path]->Create(path);

    for (auto music : palbum_[path]->content_)
        music_.insert(music);
}

void PIndex::addPlaylistToIndex(std::string name)
{
    if (pplaylist_.find(name) != pplaylist_.end())
        throw std::runtime_error("Tried to create an existing playlist!");
    
    pplaylist_[name] = std::shared_ptr<PTrack> (new PTrack);
    pplaylist_[name]->setName(name);
}

void PIndex::addSongToPlaylist(std::string song, std::string playlist)
{
    if (pplaylist_.find(playlist) == pplaylist_.end())
        throw std::runtime_error("Tried to add a song to a non-existing playlist!");
    pplaylist_[song]->Push(song);
}