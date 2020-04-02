#include "p_track.hpp"


PTrack::PTrack() { }

PTrack::PTrack(std::string name, std::vector <std::string> content):
    content_(content), name_(name) { }

std::string PTrack::getName() const
{
    return name_;
}

int PTrack::Size() const
{
    return content_.size();
}
