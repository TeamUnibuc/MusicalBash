#include "a_logger.hpp"

#include <iostream>

Logger::Logger() { }

Logger & Logger::Get()
{
    static Logger logger;
    return logger;
}

void Logger::PrintEnum (Constants::State::W type)
{
    if (type == Constants::State::W::Albums)
        std::cerr << "W-Albums";
    if (type == Constants::State::W::Create)
        std::cerr << "W-Create";
    if (type == Constants::State::W::Home)
        std::cerr << "W-Home";
    if (type == Constants::State::W::Import)
        std::cerr << "W-Import";
    if (type == Constants::State::W::Playlists)
        std::cerr << "W-Playlists";
    if (type == Constants::State::W::Queue)
        std::cerr << "W-Queue";
    if (type == Constants::State::W::ViewAlbum)
        std::cerr << "W-ViewAlbum";
    if (type == Constants::State::W::ViewPlaylist)
        std::cerr << "W-ViewPlaylist";
}