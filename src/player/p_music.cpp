 
#include "p_music.hpp"
#include "a_exceptions.hpp"

#include <stdexcept>
#include <sstream>
#include <iostream>

PMusic::PMusic() : played_count_(0), path_("None"), duration_seconds_(0) { }

PMusic::PMusic(std::string path) : played_count_(0), path_(path) {
    if (!isValidMusic())
        throw bad_behaviour("Invalid path! Music does not exist!");
        
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
    std::string pretty_path_ = path_.substr(path_.find_last_of('/') + 1);
    return pretty_path_.substr(0, pretty_path_.find_last_of('.'));
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

bool PMusic::isValidMusic() const
{
    return std::filesystem::exists(path_);
}

PMusic& PMusic::operator++()
{
    played_count_++;
    return *this;
}

PMusic& PMusic::operator+= (int x)
{
    played_count_ += x;
    return *this;
}