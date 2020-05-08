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
    double music_volume_;

public:

    /// default constructor
    Player();

    /// encodes all the info in the player (the index)
    std::string Zip() const;

    /// decodes the info from string to index
    void Unzip(const std::string& zipped);

    /// adds an album to the index
    std::shared_ptr<PAlbum> CreateAlbum(const std::string& path);

    /* creates a new playlist with a given name.
    Will launch an exception if name is taken */
    std::shared_ptr<PPlaylist> CreatePlaylist(const std::string& name);

    /// removes an album from index
    void DeleteAlbum(const std::shared_ptr<PAlbum> album);

    /// deletes a playlist
    void DeletePlaylist(const std::shared_ptr<PPlaylist> playlist);

    /// returns all the music
    std::vector <std::shared_ptr<PMusic>> getAllMusic();

    /// returns a list with all the available albums
    std::vector <std::shared_ptr<PAlbum>> getAlbums();

    /// returns a lsit with all the available playlists
    std::vector <std::shared_ptr<PPlaylist>> getPlaylists();

    /// adds a music to the playing queue
    void addMusicToQueue(const std::shared_ptr<PMusic> music);
    
    /// adds an album to the playing queue
    void addAlbumToQueue(const std::shared_ptr<PAlbum> album);

    /// adds a playlist to the playing queue
    void addPlaylistToQueue(const std::shared_ptr<PPlaylist> playlist);

    /// starts to play to play the music
    void PlayMusic();

    /// pauses the music
    void PauseMusic();

    /// stops the music and CLEARS the queue
    void StopMusic();

    /// if music is stoped but there are elements in the queue it starts playing
    void Step();

    /// returns the curent volume
    double getVolume() const;

    /// sets the curent volume
    void setVolume(double volume);

    /// returns curently playing music
    std::shared_ptr<PMusic> getActiveSong() const;

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

    /// increases volume by 1
    Player& operator++();

    /// decreases volume by 1
    Player& operator--();
};

#endif // INC_PLAYER_