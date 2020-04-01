#include "p_track.hpp"

#include <random>
#include <ctime>
#include <sstream>

namespace {
    std::mt19937 rnd(time(0));    
}

PTrack::PTrack() { }

void PTrack::Create(std::vector <std::string> content)
{
    content_ = content;
}

void PTrack::setName(std::string name)
{
    name_ = name;
}

std::string PTrack::getName() const
{
    return name_;
}

void PTrack::Push(std::string music)
{
    content_.push_back(music);
}

std::string PTrack::Zip() const
{
    std::string enc = name_ + "\n";

    for (auto i : content_)
        enc += i + "\n";
    
    return enc;
}

void PTrack::Restore(std::string zipped)
{
    std::stringstream buff(zipped);
    std::string name;
    getline(buff, name_);

    while (getline(buff, name))
        content_.push_back(name);
}

int PTrack::Size() const
{
    return content_.size();
}

std::string PTrack::FirstMusic(bool remove)
{
    if (content_.empty())
        throw std::runtime_error("Tried to get music out of an empty track!");

    auto rez = content_[0];
    if (remove)
        content_.erase(content_.begin());

    return rez;
}

std::string PTrack::RandomMusic(bool remove)
{
    if (content_.empty())
        throw std::runtime_error("Tried to get music out of an empty track!");
    
    int where = rnd() % content_.size();
    auto rez = content_[where];

    if (remove)
        content_.erase(content_.begin() + where);

    return rez;
}

std::shared_ptr<PTrack> PTrack::toPTrack()
{
    std::shared_ptr<PTrack> ptrack(new PTrack);
    (*ptrack) = (*this);
    return ptrack;
}