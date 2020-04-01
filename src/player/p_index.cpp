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
    return "";
}

void PIndex::Restore(std::string zipped)
{
    /// TODO:
    zipped = "";
}

void PIndex::CreateAlbum(std::string path)
{
    if (palbum_.find(path) != palbum_.end())
        throw std::runtime_error("Existing album is added again!");

    palbum_[path] = std::shared_ptr<PAlbum> (new PAlbum(path));

    for (auto music : palbum_[path]->content_)
        pmusic_[music->getFullPath()] = music;
}

void PIndex::CreatePlaylist(std::string name)
{
    if (pplaylist_.find(name) != pplaylist_.end())
        throw std::runtime_error("Tried to create an existing playlist!");
    
    pplaylist_[name] = std::shared_ptr<PPlaylist> (new PPlaylist(name));
}



std::vector <std::string> PIndex::getAlbums() const
{
    std::vector <std::string> ans;
    for (auto i : palbum_)
        ans.push_back(i.second->getName());

    return ans;
}

std::vector <std::string> PIndex::getPlaylists() const
{
    std::vector <std::string> ans;
    for (auto i : pplaylist_)
        ans.push_back(i.second->getName());

    return ans;
}

std::vector <std::string> PIndex::getAllMusic() const
{
    std::vector <std::string> ans;
    for (auto i : pmusic_)
        ans.push_back(i.second->getName());

    return ans;
}

std::vector <std::string> PIndex::getMusicFromPlaylist(const std::string& name) const
{
    if (pplaylist_.find(name) == pplaylist_.end())
        throw std::runtime_error("Tried to get music from non existing playlist!");

    std::vector <std::string> ans;
    for (auto i : pplaylist_.at(name)->content_)
        ans.push_back(i->getName());

    return ans;
}

std::vector <std::string> PIndex::getMusicFromAlbum(const std::string& name) const
{
    if (palbum_.find(name) == palbum_.end())
        throw std::runtime_error("Tried to get music from non existing playlist!");

    std::vector <std::string> ans;
    for (auto i : palbum_.at(name)->content_)
        ans.push_back(i->getName());

    return ans;
}

std::shared_ptr<PMusic> PIndex::getMusicPtr(const std::string& name) const
{
    if (pmusic_.find(name) == pmusic_.end())
        throw std::runtime_error("Tried to get pointer to an inexistent music!");
    return pmusic_.at(name);
}

std::shared_ptr<PAlbum> PIndex::getAlbumPtr(const std::string& name) const
{
    if (palbum_.find(name) == palbum_.end())
        throw std::runtime_error("Tried to get pointer to an inexistent album!");
    return palbum_.at(name);
    /// TODO: see if it's ok to return shared_ptr like that
}

std::shared_ptr<PPlaylist> PIndex::getPlaylistPtr(const std::string& name) const
{
    if (pplaylist_.find(name) == pplaylist_.end())
        throw std::runtime_error("Tried to get pointer to an inexistent playlist!");
    return pplaylist_.at(name);
}

void PIndex::DeleteAlbum(const std::string& name)
{
    /// when I delete an album, what happends to the removed 
    /// musics that are in some playlists?
    name[0];
    /// TODO:
}

void PIndex::DeletePlaylist(const std::string& name)
{
    if (pplaylist_.find(name) == pplaylist_.end())
        throw std::runtime_error("Tried to remove an inexistent playlist!");
    pplaylist_.erase(name);
}