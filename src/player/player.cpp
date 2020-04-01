#include "player.hpp"

Player::Player() : index_(new PIndex),
    music_queue_(new PMusicQueue),
    music_player_(new PMusicPlayer) { }

std::string Player::Zip() const
{
    return index_->Zip();
}

void Player::Unzip(const std::string& zipped)
{
    index_->Unzip(zipped);
}

void Player::CreateAlbum(const std::string& path)
{
    index_->CreateAlbum(path);
}

void Player::CreatePlaylist(const std::string& name)
{
    index_->CreatePlaylist(name);
}

void Player::DeleteAlbum(const std::string& path)
{
    index_->DeleteAlbum(path);
}

void Player::DeletePlaylist(const std::string& name)
{
    index_->DeletePlaylist(name);
}

void Player::addMusicToPlaylist(const std::string& playlist, const std::string& music)
{
    std::shared_ptr <PPlaylist> playlist_ptr = index_->getPlaylistPtr(playlist);

    playlist_ptr->addMusic(music);
}

std::vector <std::string> Player::getAllMusic()
{
    return index_->getAllMusic();
}

std::vector <std::string> Player::getAlbums()
{
    return index_->getAlbums();
}

std::vector <std::string> Player::getPlaylists()
{
    return index_->getPlaylists();
}

std::vector <std::string> Player::getMusicFromAlbum(const std::string& album)
{
    return index_->getMusicFromAlbum(album);
}

std::vector <std::string> Player::getMusicFromPlaylist(const std::string& playlist)
{
    return index_->getMusicFromPlaylist(playlist);
}

void Player::addMusicToQueue(const std::string& music)
{
    (*music_queue_) += music;
}

void Player::addAlbumToQueue(const std::string& name)
{
    std::shared_ptr<PAlbum> ptr = index_->getAlbumPtr(name);
    (*music_queue_) += ptr;
}

void Player::addPlaylistToQueue(const std::string& name)
{
    std::shared_ptr<PPlaylist> ptr = index_->getPlaylistPtr(name);
    (*music_queue_) += ptr;
}

void Player::PlayMusic()
{
    /// TODO: should see if melody ended
    if (music_player_->IsPlaying() || music_queue_->Size() == 0)
        return;
    
    std::string music = music_queue_->FirstMusic(true);
    music_player_.reset(new PMusicPlayer(music));
    music_player_->Play();
}

void Player::PauseMusic()
{
    if (music_player_->IsPlaying())
        music_player_->Pause();
}

void Player::StopMusic()
{
    music_player_.reset(new PMusicPlayer);
}
