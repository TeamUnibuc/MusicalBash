#include "p_music_queue.hpp"

#include <random>
#include <ctime>

namespace {
    std::mt19937 rnd(time(0));    
}

PMusicQueue::PMusicQueue() 
{
    name_ = "Music Queue";
}

PMusicQueue& PMusicQueue::operator += (std::shared_ptr<PMusic> music)
{
    content_.push_back(music);
    return *this;
}

PMusicQueue& PMusicQueue::operator += (std::shared_ptr<PTrack> track)
{
    for (auto i : track->GetMusic())
        content_.push_back(i);
    return *this;
}

void PMusicQueue::AddToFront(std::shared_ptr<PMusic> music)
{
    content_.insert(content_.begin(), music);
}

std::shared_ptr<PMusic> PMusicQueue::FirstMusic(bool remove)
{
    if (content_.empty())
        throw out_of_bounds_error("Tried to get music out of an empty track!");

    auto rez = content_[0];
    if (remove)
        content_.erase(content_.begin());

    return rez;
}

std::shared_ptr<PMusic> PMusicQueue::RandomMusic(bool remove)
{
    if (content_.empty())
        throw out_of_bounds_error("Tried to get music out of an empty track!");
    
    int where = rnd() % content_.size();
    auto rez = content_[where];

    if (remove)
        content_.erase(content_.begin() + where);

    return rez;
}
