#include "p_music_player.hpp"

PMusicPlayer::PMusicPlayer() { }

PMusicPlayer::PMusicPlayer(std::shared_ptr<PMusic> music) :
    p_mp3(getExtensionLC(music->getName()) == ".mp3" ? std::make_unique<sfe::Mp3>() : nullptr),
    p_music(p_mp3 ? nullptr : std::make_unique<sf::Music>()),
    music_playing(music)
{
    if (p_mp3) {
        p_mp3->openFromFile(music->getName());
        p_mp3->play();
    }
    else if (p_music) {
        p_music->openFromFile(music->getName());
        p_music->play();
    }
}

void PMusicPlayer::Play()
{
    if (p_mp3)
        p_mp3->play();
    else if (p_music)
        p_music->play();
}

void PMusicPlayer::Pause()
{
    if (p_mp3)
        p_mp3->pause();
    else if (p_music)
        p_music->pause();
}

bool PMusicPlayer::IsPlaying() const
{
    if (p_mp3)
        return p_mp3->getStatus() == p_mp3->Playing;
    else if (p_music)
        return p_music->getStatus() == p_music->Playing;
    return false;
}

bool PMusicPlayer::IsPaused() const
{
    if (p_mp3)
        return p_mp3->getStatus() == p_mp3->Paused;
    else if (p_music)
        return p_music->getStatus() == p_music->Paused;
    return false;
}

bool PMusicPlayer::IsStopped() const
{
    if (p_mp3)
        return p_mp3->getStatus() == p_mp3->Stopped;
    else if (p_music)
        return p_music->getStatus() == p_music->Stopped;
    return true;
}

void PMusicPlayer::SetVolume(double volume)
{
    if (p_mp3)
        p_mp3->setVolume(volume);
    else if (p_music)
        p_music->setVolume(volume);
}

double PMusicPlayer::GetVolume() const
{
    if (p_mp3)
        return p_mp3->getVolume();
    else if (p_music)
        return p_music->getVolume();
    return 0;
}

double PMusicPlayer::GetDuration() const
{
    if (p_mp3 || p_music)
        return music_playing->getDuration();
    return 0;
}

double PMusicPlayer::GetPlayingOffset() const
{
    if (p_mp3)
        return p_mp3->getPlayingOffset().asSeconds();
    else if (p_music)
        return p_music->getPlayingOffset().asSeconds();
    return 0;
}

void PMusicPlayer::SetPlayingOffset(double offset)
{
    if (p_mp3)
        p_mp3->setPlayingOffset(sf::seconds(offset));
    else if (p_music)
        p_music->setPlayingOffset(sf::seconds(offset));
}

std::shared_ptr<PMusic> PMusicPlayer::GetPlayingMusic() const
{
    return music_playing;
}

std::string PMusicPlayer::getExtensionLC(const std::string& filePath)
{
    size_t pos = filePath.rfind('.');
    if (pos == std::string::npos)
        return "";
    return filePath.substr(pos, filePath.size() - pos);
}