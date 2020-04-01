#include "p_index.hpp"

#include <stdexcept>
#include <sstream>

PIndex::PIndex() { }

std::string PIndex::Zip() const
{
    std::string enc;
    enc += std::to_string(pplaylist_.size()) + "\n";
    
    for (auto i : pplaylist_) {
        std::string s = i.second->Zip();
        enc += std::to_string(s.size()) + "\n" + s;
    }

    enc += std::to_string(palbum_.size()) + "\n";

    for (auto i : palbum_)
        enc += i.second->getName() + "\n";

    return enc;
}

void PIndex::Unzip(std::string zipped)
{
    std::stringstream buff(zipped);
    std::string s;
    getline(buff, s);
    int n = std::stoi(s);

    while (n--) {
        getline(buff, s);
        int sz = std::stoi(s);
        
        s = "";
        while (sz--)
            s.push_back(buff.get());

        std::shared_ptr<PPlaylist> playlist(new PPlaylist);
        playlist->Unzip(s);

        pplaylist_[playlist->getName()] = playlist;
    }

    getline(buff, s);
    n = std::stoi(s);

    while (n--) {
        getline(buff, s);
        CreateAlbum(s);
    }
}

void PIndex::CreateAlbum(std::string path)
{
    if (palbum_.find(path) != palbum_.end())
        throw std::runtime_error("Existing album is added again!");

    palbum_[path] = std::shared_ptr<PAlbum> (new PAlbum(path));

    for (auto music : palbum_[path]->content_) {
        if (pmusic_.find(music) == pmusic_.end())
            pmusic_[music] = std::shared_ptr<PMusic>(new PMusic(music));
        else
            throw std::runtime_error("There is a colision in the album musics!");
    }
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

    return pplaylist_.at(name)->content_;
}

std::vector <std::string> PIndex::getMusicFromAlbum(const std::string& name) const
{
    if (palbum_.find(name) == palbum_.end())
        throw std::runtime_error("Tried to get music from non existing playlist!");

    return palbum_.at(name)->content_;
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
}

std::shared_ptr<PPlaylist> PIndex::getPlaylistPtr(const std::string& name) const
{
    if (pplaylist_.find(name) == pplaylist_.end())
        throw std::runtime_error("Tried to get pointer to an inexistent playlist!");
    return pplaylist_.at(name);
}

void PIndex::DeleteAlbum(const std::string& name)
{
    if (palbum_.find(name) == palbum_.end())
        throw std::runtime_error("Tried to delete an album that does not exist!");

    for (auto music : palbum_[name]->content_)
        pmusic_.erase(music);

    palbum_.erase(name);
}

void PIndex::DeletePlaylist(const std::string& name)
{
    if (pplaylist_.find(name) == pplaylist_.end())
        throw std::runtime_error("Tried to remove an inexistent playlist!");
    pplaylist_.erase(name);
}