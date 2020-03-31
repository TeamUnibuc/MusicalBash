#include "p_music.hpp"

#include <stdexcept>
#include <sstream>

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

    std::string data = std::to_string(played_count_) + "\n" + path_ + "\n";
    return data;
}

void PMusic::Restore(std::string zipped)
{
    if (zipped.empty())
        throw std::runtime_error("Tried to unzip an empty string!");
    
    std::stringstream parser(zipped);
    parser >> played_count_;
    
    parser.get();
    getline(parser, path_);

    parser.get();
    if (!parser.eof())
        throw std::runtime_error("Finished parsing but buffer is not empty!");
}

std::string PMusic::getTitle() const
{
    /// maybe we sould ignore path and extension?
    return path_;
}

std::string PMusic::getFullPath() const
{
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