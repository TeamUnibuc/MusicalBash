 
#include "p_music.hpp"

#include <stdexcept>
#include <sstream>

PMusic::PMusic(std::string path) : played_count_(0), path_(path) { }

std::string PMusic::Zip() const
{
    if (path_.empty())
        throw std::runtime_error("Tried to zip an empty PMusic object!");

    std::string data = std::to_string(played_count_) + "\n" + path_ + "\n";
    return data;
}

void PMusic::Unzip(std::string zipped)
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

std::string PMusic::getFullPath() const
{
    return path_;
}

std::string PMusic::getName() const
{
    /// TODO: return name without extension
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