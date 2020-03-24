#include "sound_player.hpp"

SoundPlayer::SoundPlayer() { }

SoundPlayer::SoundPlayer(const std::string & source) :
    p_mp3(getExtensionLC(source) == ".mp3" ? std::make_unique<sfe::Mp3>() : nullptr),
    p_music(p_mp3 ? nullptr : std::make_unique<sf::Music>())
{
    if (p_mp3)
        p_mp3->openFromFile(source);
    else
        p_music->openFromFile(source);
}

void SoundPlayer::Play()
{
    if (p_mp3)
        p_mp3->play();
    else
        p_music->play();
}

void SoundPlayer::Pause()
{
    if (p_mp3)
        p_mp3->pause();
    else
        p_music->pause();
}

bool SoundPlayer::IsPlaying() const
{
    if (p_mp3)
        return p_mp3->getStatus() == p_mp3->Playing;
    else
        return p_music->getStatus() == p_music->Playing;
}

void SoundPlayer::SetVolume(float volume)
{
    if (p_mp3)
        p_mp3->setVolume(volume);
    else
        p_music->setVolume(volume);
}

std::string SoundPlayer::getExtensionLC(const std::string& filePath)
{
    size_t pos = filePath.rfind('.');
    if (pos == std::string::npos)
        return "";
    return filePath.substr(pos, filePath.size() - pos);
}