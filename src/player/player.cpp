#include "player.hpp"

Player::Player() : index_(new PIndex),
    music_queue_(new PMusicQueue),
    music_player_(new PMusicPlayer), music_volume_(Constants::kStartingVolume),
    is_suffling_(false) 
{ }

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

std::shared_ptr<PMusic> Player::CreateMusic(const std::string& path)
{
    return index_->getMusicPtr(path);
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

std::vector <std::shared_ptr<PMusic>> Player::GetPlayingQueue() const
{
    return music_queue_->GetMusic();
}

void Player::PlayMusic()
{
    if (music_player_->IsPlaying() || music_queue_->Size() == 0)
        return;
    
    if (music_player_->IsPaused()) {
        music_player_->Play();
        return;
    }

    std::shared_ptr<PMusic> music;
    if (is_suffling_)
        music = music_queue_->RandomMusic(true);
    else
        music = music_queue_->FirstMusic(true);

    /// storing that I played this music
    history_.push_back(music);

    music_player_.reset(new PMusicPlayer(music));
    music_player_->SetVolume(music_volume_);
    music_player_->Play();
}

void Player::PauseMusic()
{
    if (music_player_->IsPlaying())
        music_player_->Pause();
}

void Player::StopMusic()
{
    if (getPlayingStatus() != -1) {
        music_player_->SetPlayingOffset(0);
        PauseMusic();
    }
}

void Player::Step()
{
    if (getPlayingStatus() == -1)
        PlayMusic();
}

double Player::getVolume() const
{
    if (getPlayingStatus() == -1)
        return music_volume_;

    return music_player_->GetVolume();
}

void Player::setVolume(double volume)
{
    music_player_->SetVolume(volume);
}

void Player::Prev()
{
    if (history_.empty())
        return; // nothing to do

    /// first case: reset song to offset 0  
    if (getPlayingStatus() != -1 && getActiveSongPlayingOffset() > 5) {
        setActiveSongPlayingOffset(0);
        return;
    }
    
    /// second case: play last song in queue
    if (getPlayingStatus() == -1 || history_.size() == 1) {
        music_player_.reset(new PMusicPlayer(history_.back()));
        music_player_->SetVolume(music_volume_);
        return;
    }

    /// last case: music is playing and there are at least 2 elem in history
    music_queue_->AddToFront(history_.back());
    history_.pop_back();
    music_player_.reset(new PMusicPlayer(history_.back()));
    music_player_->SetVolume(music_volume_);
}

void Player::Next()
{
    music_player_.reset(new PMusicPlayer);
    music_player_->SetVolume(music_volume_);
    PlayMusic();
}

std::shared_ptr<PMusic> Player::getActiveSong() const
{
    std::shared_ptr<PMusic> ans;
    
    if (music_player_->IsStopped()) {
        ans = std::make_shared<PMusic>();
        return ans;
    }

    ans = music_player_->GetPlayingMusic();
    if (!ans)
        throw std::runtime_error("Active song expected to be\
        Not Null but found Null!");

    return ans;    
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

bool Player::getSufflingStatus() const
{
    return is_suffling_;
}

void Player::setSufflingStatus(bool suffle)
{
    is_suffling_ = suffle;
}

Player& Player::operator++()
{
    music_volume_ = std::min(music_volume_ + Constants::kVolumeStep, 100.);
    setVolume(music_volume_);
    return *this;
}

Player& Player::operator--()
{
    music_volume_ = std::max(music_volume_ - Constants::kVolumeStep, 0.);
    setVolume(music_volume_);
    return *this;
}