#ifndef INC_P_INDEX_
#define INC_P_INDEX_

#include "p_album.hpp"
#include "p_track.hpp"

#include <map>
#include <set>
#include <memory>
#include <string>

/**
 *  Class storing the information about all the albums, playlists and musics.
 */


class PIndex
{
    std::map <std::string, std::shared_ptr<PTrack>> pplaylist_;
    std::map <std::string, std::shared_ptr<PAlbum>> palbum_;
    std::set <std::string> music_;

public:
    /// constructor
    PIndex();

    /// converts the content of the class, playlists, albums and musics to a string
    std::string Zip() const;

    /// restores the content of the class from the zip string
    void Restore(std::string zipped);

    /// adds a new album to the index
    void addAlbumToIndex(std::string path);

    /// creates a new playlist
    void addPlaylistToIndex(std::string name);

    /// adds a song to a playlist
    void addSongToPlaylist(std::string song, std::string playlist);
};

#endif // INC_P_INDEX_