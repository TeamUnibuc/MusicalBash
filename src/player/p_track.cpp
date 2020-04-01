#include "p_track.hpp"

#include <sstream>

PTrack::PTrack() { }

PTrack::PTrack(std::string name, std::vector <std::shared_ptr<PMusic>> content):
    content_(content), name_(name) { }

void PTrack::setName(std::string name)
{
    name_ = name;
}

std::string PTrack::getName() const
{
    return name_;
}

void PTrack::addMusic(std::shared_ptr<PMusic> music)
{
    content_.push_back(music);
}

std::string PTrack::Zip() const
{
    /// TODO:
    return "";
}

void PTrack::Unzip(std::string zipped)
{
    /// TODO:
    zipped = "";
}

int PTrack::Size() const
{
    return content_.size();
}
