#include "p_music.hpp"

#include <stdexcept>

PMusic::PMusic() : played_count_(0), path_("") { }

void PMusic::Create(std::string path)
{
    if (path.empty())
        throw std::runtime_error("Tried to create a music with an empty path!");
    if (!path_.empty())
        throw std::runtime_error("Tried to overrite an existing music!");
    path_ = path;
}

std::string PMusic::Zip() const
{
    if (path_.empty())
        throw std::runtime_error("Tried to zip an empty PMusic object!");

    return path_ + "\0" + std::to_string(played_count_);
}

void PMusic::Restore(std::string zipped)
{
    auto separation = zipped.find("\0");
    if (separation == std::string::npos)
        throw std::runtime_error("Tried to restore an invalid string!");

    path_ = zipped.substr(0, separation);
    played_count_ = std::stoi(zipped.substr(separation + 1));

    if (path_.empty() || played_count_ < 0)
        throw std::runtime_error("Invalid restore!");
}

std::string PMusic::getTitle() const
{
    /// maybe we sould ignore path and extension?
    return path_;
}

int PMusic::getPlayedCount() const
{
    return played_count_;
}

void PMusic::addPlayedCount()
{
    played_count_++;
}