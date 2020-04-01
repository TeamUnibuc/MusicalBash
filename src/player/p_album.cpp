#include "p_album.hpp"

#include <random>
#include <ctime>
#include <sstream>


PAlbum::PAlbum() { }

void PAlbum::Create(std::string album_path)
{
    album_path_ = album_name_ = album_path;
}

std::string PAlbum::Zip() const
{
    std::string enc = album_path_ + "\n" + album_name_ + "\n";
    return enc;
}

void PAlbum::Restore(std::string zipped)
{
    std::stringstream buff(zipped);
    getline(buff, album_path_);
    getline(buff, album_name_);
    if (album_name_.empty() || album_path_.empty())
        throw std::runtime_error("PAlbum unable to restore");
}

int PAlbum::Size() const
{
    return content_.size();
}

std::shared_ptr<PTrack> PAlbum::toPTrack()
{
    std::shared_ptr<PTrack> ptrack(new PTrack);
    ptrack->content_ = content_;

    return ptrack;
}
