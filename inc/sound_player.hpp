#ifndef INC_SOUND_
#define INC_SOUND_

#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

class SoundPlayer {
protected:
    sf::Music music;
public:
    SoundPlayer();
    SoundPlayer(const std::string & source);

    void Play();
    void Pause();
    bool IsPlaying() const;
    void SetVolume(float volume);
};

#endif // INC_SOUND_
