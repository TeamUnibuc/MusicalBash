#include "p_index.hpp"

#include <stdexcept>
#include <sstream>
#include <fstream>

PIndex::PIndex() { }

void PIndex::Zip() const
{

    std::string enc;
    enc += std::to_string(palbum_.size()) + "\n";
    
    for (auto i : palbum_)
        enc += i->GetName() + "\n";

    enc += std::to_string(pplaylist_.size()) + "\n";

    for (auto i : pplaylist_) {
        std::vector <std::shared_ptr<PMusic>> content = i->GetMusic();
        enc += i->GetName() + "\n";
        enc += std::to_string(content.size()) + "\n";
        for (auto c : content)
            enc += c->getName() + "\n";
    }

    DBHandler::StoreData(enc);
}

void PIndex::Unzip()
{

    std::stringstream buff(DBHandler::ExtractData());
    std::string s;
    getline(buff, s);
    if (s.empty())
        return;
    int n = std::stoi(s);

    while (n--) {
        getline(buff, s);
        CreateAlbum(s);
    }

    getline(buff, s);
    n = std::stoi(s);

    while (n--) {
        getline(buff, s);
        std::shared_ptr<PPlaylist> ptr = CreatePlaylist(s);

        getline(buff, s);
        int sz = std::stoi(s);
        
        while (sz--) {
            getline(buff, s);
            if (pmusic_.find(s) == pmusic_.end()) {
                try {
                    auto m_ptr = std::shared_ptr<PMusic> (new PMusic(s));
                    pmusic_[s] = m_ptr;
                }
                catch (...) {
                    Logger::Get() << "Found invalid music: " << s << '\n';
                }
            }
            if (pmusic_.find(s) != pmusic_.end())
                ptr->AddMusic(pmusic_[s]);
        }
    }
}

std::shared_ptr<PAlbum> PIndex::CreateAlbum(std::string path)
{
    /// if the album already exists then re-scan it
    for (auto i : palbum_) {
        if (i->GetName() == path) {
            (*i) = PAlbum(path, pmusic_);
            return i;
        }
    }
    
    palbum_.push_back(std::shared_ptr<PAlbum> (new PAlbum(path, pmusic_)));
    return palbum_.back();
}

std::shared_ptr<PPlaylist> PIndex::CreatePlaylist(std::string name)
{
    pplaylist_.push_back(std::shared_ptr<PPlaylist> (new PPlaylist(name)));
    return pplaylist_.back();
}

std::vector <std::shared_ptr<PAlbum>> PIndex::getAlbums() const
{
    return palbum_;
}

std::vector <std::shared_ptr<PPlaylist>> PIndex::getPlaylists() const
{
    return pplaylist_;
}

PTrack PIndex::getAllMusic() const
{
    PTrack ans;
    for (auto i : pmusic_)
        if (i.second->isValidMusic())
            ans.AddMusic(i.second);

    return std::move(ans);
}

std::shared_ptr<PMusic> PIndex::getMusicPtr(const std::string& name)
{
    if (pmusic_.find(name) == pmusic_.end())
        pmusic_[name] = std::make_shared<PMusic>(name);
    return pmusic_.at(name);
}

void PIndex::DeleteAlbum(const std::shared_ptr<PAlbum> album)
{
    if (find(palbum_.begin(), palbum_.end(), album) == palbum_.end())
        throw player_runtime_error("Tried to delete an album that does not exist!");

    palbum_.erase(find(palbum_.begin(), palbum_.end(), album));
}

void PIndex::DeletePlaylist(const std::shared_ptr<PPlaylist> playlist)
{
    if (find(pplaylist_.begin(), pplaylist_.end(), playlist) == pplaylist_.end())
        throw player_runtime_error("Tried to delete an album that does not exist!");

    pplaylist_.erase(find(pplaylist_.begin(), pplaylist_.end(), playlist));
}

PIndex& PIndex::operator+= (const std::shared_ptr<PAlbum> album)
{
    for (auto i : palbum_) {
        if (i->GetName() == album->GetName()) {
            return *this;
        }
    }
    
    palbum_.push_back(album);
    return *this;
}

PIndex& PIndex::operator+= (const std::shared_ptr<PPlaylist> playlist)
{
    for (auto i : pplaylist_) {
        if (i->GetName() == playlist->GetName()) {
            return *this;
        }
    }
    
    pplaylist_.push_back(playlist);
    return *this;
}