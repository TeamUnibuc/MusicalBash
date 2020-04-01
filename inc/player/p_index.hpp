#ifndef INC_P_INDEX_
#define INC_P_INDEX_

#include "p_album.hpp"
#include "p_playlist.hpp"
#include "p_music.hpp"

#include <map>
#include <set>
#include <memory>
#include <string>

/**
 *  Class storing the information about all the albums, playlists and musics.
 */
class PIndex
{
    std::map <std::string, std::shared_ptr<PPlaylist>> pplaylist_;
    std::map <std::string, std::shared_ptr<PAlbum>> palbum_;
    std::map <std::string, std::shared_ptr<PMusic>> pmusic_;

public:
    /// constructor
    PIndex();

    /// converts the content of the class, playlists, albums and musics to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    /// adds a new album to the index
    void CreateAlbum(std::string path);

    /// creates a new playlist
    void CreatePlaylist(std::string name);

    /// returns list of albums
    std::vector <std::string> getAlbums() const;

    /// returns list of playlists
    std::vector <std::string> getPlaylists() const;
    
    /// returns all the music
    std::vector <std::string> getAllMusic() const;
    
    /// returns all the music from a playlist
    std::vector <std::string> getMusicFromPlaylist(const std::string& name) const;
    
    /// returns all the music from an album
    std::vector <std::string> getMusicFromAlbum(const std::string& name) const;

    /// returns shared_ptr with given music
    std::shared_ptr<PMusic> getMusicPtr(const std::string& name) const;

    /// returns shared_ptr with given album
    std::shared_ptr<PAlbum> getAlbumPtr(const std::string& name) const;

    /// returns shared_ptr with given playlist
    std::shared_ptr<PPlaylist> getPlaylistPtr(const std::string& name) const;

    /// deletes an album. Throw error if it does not exist
    void DeleteAlbum(const std::string& name);

    /// deletes a playlist. Throws error if is does not exist
    void DeletePlaylist(const std::string& name);
};

#endif // INC_P_INDEX_