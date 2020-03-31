#include "p_track.hpp"

#include <random>
#include <ctime>

namespace {
    std::mt19937 rnd(time(0));    
}

PTrack::PTrack() { }

void PTrack::Create(std::vector <std::shared_ptr<PMusic>> content)
{
    content_ = content;
}

void PTrack::Push(std::shared_ptr<PMusic> music)
{
    content_.push_back(music);
}

std::string PTrack::Zip() const
{
    /// TODO: Find a way to encode info
    return "";
}

void PTrack::Restore(std::string zipped)
{
    /// TODO: see above
    zipped += "";
}

int PTrack::Size() const
{
    return content_.size();
}

std::shared_ptr<PMusic> PTrack::FirstMusic(bool remove)
{
    if (content_.empty())
        throw std::runtime_error("Tried to get music out of an empty track!");

    auto rez = content_[0];
    if (remove)
        content_.erase(content_.begin());

    return rez;
}

std::shared_ptr<PMusic> PTrack::RandomMusic(bool remove)
{
    if (content_.empty())
        throw std::runtime_error("Tried to get music out of an empty track!");
    
    int where = rnd() % content_.size();
    auto rez = content_[where];

    if (remove)
        content_.erase(content_.begin() + where);

    return rez;
}
