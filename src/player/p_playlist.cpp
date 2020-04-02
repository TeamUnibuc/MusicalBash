#include "p_playlist.hpp"

#include <sstream>

PPlaylist::PPlaylist() { }

PPlaylist::PPlaylist(std::string name)
{
    name_ = name;
}

void PPlaylist::addMusic(std::string music)
{
    content_.push_back(music);
}

std::string PPlaylist::Zip() const
{
    std::string s = name_ + "\n" + std::to_string(content_.size()) + "\n";
    for (auto i : content_)
        s += i + "\n";
    return s;
}

void PPlaylist::Unzip(std::string zipped)
{
    std::stringstream buff(zipped);
    std::string s;

    getline(buff, s);
    content_.resize(std::stoi(s));

    getline(buff, name_);

    for (auto & i : content_)
        getline(buff, i);
}