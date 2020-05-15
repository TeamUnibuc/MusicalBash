#include "p_track.hpp"


PTrack::PTrack() { }

PTrack::PTrack(PTrack && oth)
{
    content_ = std::move(oth.content_);
    name_ = std::move(oth.name_);
}

PTrack & PTrack::operator=(PTrack && oth)
{
    content_ = std::move(oth.content_);
    name_ = std::move(oth.name_);
    return *this;
}

std::string PTrack::GetName() const
{
    return name_;
}

int PTrack::Size() const
{
    return content_.size();
}

std::vector <std::shared_ptr<PMusic>> PTrack::GetMusic()
{
    std::vector <std::shared_ptr<PMusic>> new_content_;
    for (auto & i : content_)
        if (i->isValidMusic())
            new_content_.push_back(i);

    content_ = std::move(new_content_);
    return content_;
}


void PTrack::AddMusic(std::shared_ptr<PMusic> music)
{
    content_.push_back(music);
}
