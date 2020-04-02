#ifndef INC_PLAYER_
#define INC_PLAYER_

#include "p_index.hpp"
#include "p_album.hpp"
#include "p_music.hpp"
#include "p_music_player.hpp"
#include "p_playlist.hpp"
#include "p_music_queue.hpp"

#include <vector>
#include <string>
#include <memory>

/**
 * This is the main player class, taking care of basically all of the player tasks.
 * It contains:
 * 1. The index, with the list of all the music, playlists and albums
 * 2. The playing track
 * 
 * It is able to basically receive any command from the UI
 * WARNING: ALL names are given with full path / extension
 * and player expects to get them back in the same way
 */
class Player 
{
    std::shared_ptr <PIndex> index_;
    std::shared_ptr <PMusicQueue> music_queue_;
    std::shared_ptr <PMusicPlayer> music_player_;
    
public:

    /// default constructor
    Player();

    /// encodes all the info in the player (the index)
    std::string Zip() const;

    /// decodes the info from string to index
    void Unzip(const std::string& zipped);

    /// adds an album to the index
    void CreateAlbum(const std::string& path);

    /* creates a new playlist with a given name.
    Will launch an exception if name is taken */
    void CreatePlaylist(const std::string& name);

    /// removes an album from index
    void DeleteAlbum(const std::string& path);

    /// deletes a playlist
    void DeletePlaylist(const std::string& name);

    /// adds a music to a playlist
    void addMusicToPlaylist(const std::string& playlist, const std::string& music);

    /// returns all the music
    std::vector <std::string> getAllMusic();

    /// returns a list with all the available albums
    std::vector <std::string> getAlbums();

    /// returns a lsit with all the available playlists
    std::vector <std::string> getPlaylists();

    /// returns all the music from an album
    std::vector <std::string> getMusicFromAlbum(const std::string& album);

    /// returns all the music from a playlist
    std::vector <std::string> getMusicFromPlaylist(const std::string& playlist);

    /// adds a music to the playing queue
    void addMusicToQueue(const std::string& music);
    
    /// adds an album to the playing queue
    void addAlbumToQueue(const std::string& name);

    /// adds a playlist to the playing queue
    void addPlaylistToQueue(const std::string& name);

    /// starts to play to play the music
    void PlayMusic();

    /// pauses the music
    void PauseMusic();

    /// stops the music
    void StopMusic();

    /// returns the curent volume
    double getVolume() const;

    /// sets the curent volume
    void setVolume(double volume);

    /// returns length of active song.
    double getActiveSongDuration() const;

    /// returns curently played of active song
    double getActiveSongPlayingOffset() const;

    /// sets where the cursor is
    void setActiveSongPlayingOffset(double offset);

    /**
     *  returns the curent status.
     *  -1 for stopped
     *  0 for playing
     *  1 for paused
     */
    int getPlayingStatus() const;
};

#endif // INC_PLAYER_