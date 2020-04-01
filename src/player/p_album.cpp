#include "p_album.hpp"

#include <random>
#include <ctime>
#include <sstream>


PAlbum::PAlbum() { }

PAlbum::PAlbum(std::string album_path) 
{
    name_ = album_path;
    /// TODO: Insert content via a command
}
