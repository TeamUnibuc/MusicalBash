#include "player.hpp"

Player::Player() : index_(new PIndex),
    music_queue_(new PMusicQueue),
    music_player_(new PMusicPlayer), music_volume_(50) { }

std::string Player::Zip() const
{
    return index_->Zip();
}

void Player::Unzip(const std::string& zipped)
{
    index_->Unzip(zipped);
}

std::shared_ptr<PAlbum> Player::CreateAlbum(const std::string& path)
{
    return index_->CreateAlbum(path);
}

std::shared_ptr<PPlaylist> Player::CreatePlaylist(const std::string& name)
{
    return index_->CreatePlaylist(name);
}

void Player::DeleteAlbum(const std::shared_ptr<PAlbum> album)
{
    index_->DeleteAlbum(album);
}

void Player::DeletePlaylist(const std::shared_ptr<PPlaylist> playlist)
{
    index_->DeletePlaylist(playlist);
}

std::vector <std::shared_ptr<PMusic>> Player::getAllMusic()
{
    return index_->getAllMusic();
}

std::vector <std::shared_ptr<PAlbum>> Player::getAlbums()
{
    return index_->getAlbums();
}

std::vector <std::shared_ptr<PPlaylist>> Player::getPlaylists()
{
    return index_->getPlaylists();
}

void Player::addMusicToQueue(const std::shared_ptr<PMusic> music)
{
    (*music_queue_) += music;
}  

void Player::addAlbumToQueue(const std::shared_ptr<PAlbum> album)
{
    (*music_queue_) += album;
}

void Player::addPlaylistToQueue(const std::shared_ptr<PPlaylist> playlist)
{
    (*music_queue_) += playlist;
}

void Player::PlayMusic()
{
    if (music_player_->IsPlaying() || music_queue_->Size() == 0)
        return;
    
    if (music_player_->IsPaused()) {
        music_player_->Play();
        return;
    }

    std::shared_ptr<PMusic> music = music_queue_->FirstMusic(true);
    music_player_.reset(new PMusicPlayer(music));
    music_player_->Play();
    music_player_->SetVolume(music_volume_);
}

void Player::PauseMusic()
{
    if (music_player_->IsPlaying())
        music_player_->Pause();
}

void Player::StopMusic()
{
    music_player_.reset(new PMusicPlayer);
    music_queue_.reset(new PMusicQueue);
}

void Player::Step()
{
    if (getPlayingStatus() == -1)
        PlayMusic();
}

double Player::getVolume() const
{
    return music_volume_;
}

void Player::setVolume(double volume)
{
    if (volume > 100. || volume < 0.)
        throw std::runtime_error("Invalid volume");
    music_volume_ = volume;
    music_player_->SetVolume(volume);
}

std::shared_ptr<PMusic> Player::getActiveSong() const
{
    std::shared_ptr<PMusic> ans = music_player_->GetPlayingMusic();
    if (ans)
        return ans;
    // need to create a new PMusic empty
    std::shared_ptr<PMusic> ans(new PMusic);
}

double Player::getActiveSongDuration() const
{
    return music_player_->GetDuration();
}

double Player::getActiveSongPlayingOffset() const
{
    return music_player_->GetPlayingOffset();
}

void Player::setActiveSongPlayingOffset(double offset)
{
    music_player_->SetPlayingOffset(offset);
}

int Player::getPlayingStatus() const
{
    if (!music_player_)
        return -1;
    if (music_player_->IsPaused())
        return 1;
    if (music_player_->IsPlaying())
        return 0;
    return -1;
}

Player& Player::operator++()
{
    music_volume_ = std::min(music_volume_ + 1, 100.);
    setVolume(music_volume_);
    return *this;
}

Player& Player::operator--()
{
    music_volume_ = std::max(music_volume_ - 1, 0.);
    setVolume(music_volume_);
    return *this;
}
