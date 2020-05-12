#ifndef INC_P_INDEX_
#define INC_P_INDEX_

#include "p_album.hpp"
#include "p_playlist.hpp"
#include "p_music.hpp"

#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>

/**
 *  Class storing the information about all the albums, playlists and musics.
 */
class PIndex
{
    std::vector <std::shared_ptr<PPlaylist>> pplaylist_;
    std::vector <std::shared_ptr<PAlbum>> palbum_;
    std::map <std::string, std::shared_ptr<PMusic>> pmusic_;

public:
    /// constructor
    PIndex();

    /// converts the content of the class, playlists, albums and musics to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Unzip(std::string zipped);

    /// adds a new album to the index
    std::shared_ptr<PAlbum> CreateAlbum(std::string path);

    /// creates a new playlist
    std::shared_ptr<PPlaylist> CreatePlaylist(std::string name);

    /// returns list of albums
    std::vector <std::shared_ptr<PAlbum>> getAlbums() const;

    /// returns list of playlists
    std::vector <std::shared_ptr<PPlaylist>> getPlaylists() const;
    
    /// returns all the music
    std::vector <std::shared_ptr<PMusic>> getAllMusic() const;
    
    /// returns shared_ptr with given music
    std::shared_ptr<PMusic> getMusicPtr(const std::string& name);

    /// deletes an album. Throw error if it does not exist
    void DeleteAlbum(const std::shared_ptr<PAlbum> album);

    /// deletes a playlist. Throws error if is does not exist
    void DeletePlaylist(const std::shared_ptr<PPlaylist> playlist);
};

#endif // INC_P_INDEX_