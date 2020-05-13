 
#include "p_music.hpp"

#include <stdexcept>
#include <sstream>
#include <iostream>

PMusic::PMusic() : played_count_(0), path_("None"), duration_seconds_(0) { }

PMusic::PMusic(std::string path) : played_count_(0), path_(path) {
    bool duration_calculated = false;
    /// If it is an mp3 file, then use the specific command
    if (path.size() > 3) {
        if (path.substr(path.size() - 4, 4) == ".mp3") {
            // std::cerr << path << '\n';

            CMp3FileDuration command(path);
            command.Execute();
            duration_seconds_ = command.GetResult();
            duration_calculated = true;
        }
    }

    if (!duration_calculated) {
        sf::Music myMusic;
        myMusic.openFromFile(path);
        duration_seconds_ = myMusic.getDuration().asSeconds();
        duration_calculated = true;
    }
}

std::string PMusic::getSongNameWithoutPath() const
{
    int last_backslash = -1;
    for (int i = 0; i < (int)path_.size(); i++)
        if (path_[i] == '/')
            last_backslash = i;
    return path_.substr(last_backslash + 1);
}

std::string PMusic::Zip() const
{
    if (path_.empty())
        throw zip_error("Tried to zip an empty PMusic object!");

    std::string data = std::to_string(played_count_) + "\n" + path_ + "\n";
    return data;
}

void PMusic::Unzip(std::string zipped)
{
    if (zipped.empty())
        throw zip_error("Tried to unzip an empty string!");
    
    std::stringstream parser(zipped);
    parser >> played_count_;
    
    parser.get();
    getline(parser, path_);

    parser.get();
    if (!parser.eof())
        throw std::runtime_error("Finished parsing but buffer is not empty!");
}

std::string PMusic::getName() const
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

double PMusic::getDuration() const
{
    return duration_seconds_;
}