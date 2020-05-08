#include "p_track.hpp"


PTrack::PTrack() { }

std::string PTrack::GetName() const
{
    return name_;
}

int PTrack::Size() const
{
    return content_.size();
}

std::vector <std::shared_ptr<PMusic>> PTrack::GetMusic() const
{
    return content_;
}