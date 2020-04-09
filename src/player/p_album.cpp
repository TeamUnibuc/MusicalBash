#include "p_album.hpp"
#include "c_file_system.hpp"

PAlbum::PAlbum() { }

PAlbum::PAlbum(std::string album_path) 
{
    name_ = album_path;
    CFileSystem filesys(name_);

    content_ = filesys.RecursiveGetMusic();
}
