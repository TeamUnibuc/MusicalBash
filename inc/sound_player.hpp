<<<<<<< HEAD
#ifndef INC_SOUND_
#define INC_SOUND_

#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

class SoundPlayer
{
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
=======
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
>>>>>>> 9947741ebd0c1bd6a57f2afe35f25a922e58c301
