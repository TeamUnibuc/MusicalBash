#include "sound_player.hpp"
using namespace std;

SoundPlayer::SoundPlayer() { }

SoundPlayer::SoundPlayer(const string & source)
{
    if(!music.openFromFile(source))
        throw runtime_error("Unable to open " + source);
}

void SoundPlayer::Play()
{
    music.play();
}

void SoundPlayer::Pause()
{
    music.pause();
}

bool SoundPlayer::IsPlaying() const
{
    return music.getStatus() == music.Playing;
}

void SoundPlayer::SetVolume(float volume)
{
    music.setVolume(volume);
}